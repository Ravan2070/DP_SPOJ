//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//SPOJ TWENDS - Two Ends
//DP + two pointers
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
//dp[i][j]--> max score first player can get;
int idx;
void freakyoutput(ll ans)
{
    idx++;
    cout<<"In game "<<idx<<", the greedy strategy might lose by as many as "<<ans<<" points.\n";
}
void solve(int n)
{
  int i,j,interval;
  ll A[n],dp[n][n],sum=0ll;
  fo(i,0,n)fo(j,0,n)dp[i][j]=0ll;
  
  fo(i,0,n)
  {
      cin>>A[i];
      sum+=A[i];
      dp[i][i]=A[i];
  }
  
  for(interval=2;interval<=n;interval++)
  {
      for(i=0;i+interval-1<n;i++)
      {
          j=i+interval-1;
          if(interval==2)
          {
              dp[i][j]=max(A[i],A[j]);
          }
          else
          {
              int l1,r1,l2,r2;
              if(A[i+1]>=A[j])l1=i+2,r1=j;
              else l1=i+1,r1=j-1;
              
              if(A[i]>=A[j-1])l2=i+1,r2=j-1;
              else l2=i,r2=j-2;
            
              dp[i][j]=max(A[i]+dp[l1][r1],A[j]+dp[l2][r2]);
          }
      }
  }
 
  freakyoutput(2ll*dp[0][n-1]-sum);
  
}
int main()
{
   fastio
   while(true)
   {   
       int n;cin>>n;
       if(n==0)break;
       solve(n);
   }
  return 0;
}
