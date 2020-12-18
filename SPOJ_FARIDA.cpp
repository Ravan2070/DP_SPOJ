//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//SPOJ FARIDA - Princess Farida
//Simple DP
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
vector<int>v;
vector<ll>dp;
int n,idx;
void freakoutput(ll ans)
{
    idx++;
    cout<<"Case "<<idx<<": "<<ans<<"\n";
}
void solve()
{
    
    cin>>n;
    if(n==0)
    {
        freakoutput(0);
        return;
    }
    v=vector<int>(n);
    dp=vector<ll>(n,0ll);
    int i;
    fo(i,0,n)cin>>v[i];
    
    ll mx=0ll;
    for(i=n-1;i>=0;i--)
    {
        dp[i]=v[i];
        if(i+2<n)
        {
            mx=max(mx,dp[i+2]);
           
        }
        ll last=0ll;
        if(i+1<n)last=dp[i+1];
         dp[i]=max(dp[i],max(v[i]+mx,last));
    }
    freakoutput(dp[0]);
}
int main()
{
   fastio
   Test_cases
   solve();
  return 0;
}
