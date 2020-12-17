//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//SPOJ WACHOVIA - Wachovia Bank
//Simple 0-1 Knapsack
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<pair<ll,ll>> vii;
typedef pair<ll,ll> pii;
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
const ll INF = (ll)2e18 + 77;
struct item{
  ll weight;
  ll value;  
};
//dp[i][j]--> max value obtained when  weight i and considering first j elements;
void solve()
{
  int K,M,i;cin>>K>>M;
  item I[M+1];
  foe(i,1,M)cin>>I[i].weight>>I[i].value;
  
  ll dp[K+1][M+1];
  foe(i,0,M)dp[0][i]=0;
  foe(i,0,K)dp[i][0]=0;
  
  int wt,pos;
  foe(wt,1,K)
  {
      foe(pos,1,M)
      {
          dp[wt][pos]=dp[wt][pos-1];
          if(wt-I[pos].weight>=0)dp[wt][pos]=max(dp[wt][pos],I[pos].value+dp[wt-I[pos].weight][pos-1]);
      }
  }
  cout<<"Hey stupid robber, you can get "<<dp[K][M]<<".\n";
}
int main()
{
   fastio
   Test_cases
   solve();
  return 0;
}
