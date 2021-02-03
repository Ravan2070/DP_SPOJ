//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//SPOJ ACTIV - Activities
//DP + BS
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<int,int> pii;
typedef map<ll,ll> mii;
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define sp(x) fixed<<setprecision(x)
#define sz(x) (ll)(x.size())
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
const int MOD=(int)1e8;
void solve()
{
  int n,i;
  while(true)
  {
      cin>>n;
      if(n==-1)break;
      vector<pii>tl(n);
      fo(i,0,n)cin>>tl[i].first>>tl[i].second;
      
      sort(all(tl));
      vector<vector<ll>>dp(n+1,vector<ll>(2,0));
      
      for(i=n-1;i>=0;i--)
      {
          int j=lower_bound(all(tl),mp(tl[i].second,-1))-tl.begin();
          dp[i][0]=1;
          if(j<n)dp[i][0]=(dp[i][0]+dp[j][1])%MOD;
          dp[i][1]=(dp[i][0]+dp[i+1][1])%MOD;
      }
      vector<ll>eight(8,0);
      ll ans=(dp[0][1]%MOD);
      fo(i,0,8)
      {
          eight[7-i]=(ans%10);
          ans/=10;
      }
      for(auto it:eight)cout<<it;
      cout<<"\n";
      
  }
  
}
int main()
{
   fastio
   solve();
  return 0;
}
