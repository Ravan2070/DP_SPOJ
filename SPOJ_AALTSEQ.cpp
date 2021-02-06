//Ravan_2070
//AALTSEQ - Alternating Sequences
//DP
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
int sign(int x)
{
    if(x>0)return 1;
    else return 0;
}
void solve()
{
    int n,i,j;cin>>n;
    int a[n];
    fo(i,0,n)cin>>a[i];
    
    int dp[n],ans=1;//dp[i]--> considering from ith element what is longest alternating sequence

    for(i=n-1;i>=0;i--)
    {
        dp[i]=1;
        for(j=i+1;j<n;j++)
        {
           
            int s1,s2;
            s1=sign(a[i]);s2=sign(a[j]);
            if((s1^s2)&&(abs(a[j])>abs(a[i])))
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    
}
int main()
{
    fastio
    //Test_cases
    solve();
    return 0;
}
