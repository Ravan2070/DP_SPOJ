//Ravan_2070
//ADACOINS - Ada and Coins
//DP(Knapsack like not exact) + datastructes
//https://www.youtube.com/watch?v=jqJ5s077OKo&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80
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
    int n,q,i;cin>>n>>q;
    int coins[n],maxSum=(int)1e5+1;
    fo(i,0,n)cin>>coins[i];
    bitset<100001>dp;
    dp[0]=1;//as it is  possible make an empty subset;
    fo(i,0,n)
    {
        dp=dp|(dp<<coins[i]);
        //Above is equivalent to
        /*
            for(j=maxSum;j>=coins[i];j--)if(dp[j-coins[i]]==1)dp[j]=1;
        
        */
    }
    vector<ll>ps(maxSum,0ll);
    fo(i,1,maxSum)
    {
        ps[i]=ps[i-1];
        if(dp[i]==1)ps[i]++;
    }
    
    int b,e;
    while(q--)
    {
        cin>>b>>e;
        cout<<ps[e]-ps[b-1]<<"\n";
    }
}
int main()
{
    fastio
    //Test_cases
    solve();
    return 0;
}
