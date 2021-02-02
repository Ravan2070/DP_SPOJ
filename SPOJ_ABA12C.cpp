//Ravan_2070
//ABA12C - Buying Apples!
//Simple DP
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define Test_cases ll TC;cin>>TC;while(TC--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(x) (ll)x.size()
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
const ll INF=(ll)2e18+77;
void solve()
{
    int n,k,i,p;cin>>n>>k;
    vector<pair<int,int>>v;
    vector<int>dp(k+1,1e9);
    for(i=1;i<=k;i++)    
    {
        cin>>p;
        if(p!=-1)v.pb(mp(i,p));
    }
    
    dp[0]=0;
    for(int wt=1;wt<=k;wt++)
    {
        fo(i,0,sz(v))
        {
            if(wt-v[i].F>=0)dp[wt]=min(dp[wt],v[i].S+dp[wt-v[i].F]);
        }
    } 
   
    if(dp[k]==1e9)dp[k]=-1;
    cout<<dp[k]<<"\n";
}
int main()
{
    fastio
    Test_cases
    solve();
    return 0;
}
