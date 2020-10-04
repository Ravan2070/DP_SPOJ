//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//DP(or better 2D -dp)
//SPOJ --> SAMER08C - Candy
/*
    I ♥ CLARICE STARLING

    EXPLAINATION BELOW->
    Hint: 
    1)Just added some constraints on choice..
    2)Order of choice of candies didnot matter so(choosing ascending or random for particular set doesnot matter)
    3)Same set of choices of candies lead finally to same dp state 
    4)Commented forloop help understand more about constraints on choice added by me
      ,even helps to understand role of mxr,mxc...

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define fr(i,b,a) for(i=b;i>a;i--)
#define fre(i,b,a) for(i=b;i>=a;i--)
#define sz(x) (ll)x.size();
#define all(x) x.begin(),x,end();
#define pb push_back
#define mp make_pair
#define  F first
#define  S second
#define lb lower_bound
#define ub upper_bound
#define Test_cases ll TC;cin>>TC;while(TC--)
#define MOD7 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
void solve()
{
    while(true)
    {
        int n,m,i,j;cin>>n>>m;
        if(n==0&&m==0)return;
        
        ll M[n][m];
        fo(i,0,n)
        fo(j,0,m)cin>>M[i][j];
        vector<vector<ll>>dp(n+2,vector<ll>(m+2,0ll));
        ll mx=0ll;
        ll mxr=0ll;
        ll mxc;
        for(i=n-1;i>=0;i--)
        {
            mxc=0ll;
            for(j=0;j<m;j++)mxr=max(mxr,dp[i+2][j]);
            for(j=m-1;j>=0;j--)
            {
                /*int k;
                for(k=j+2;k<m+2;k++)dp[i][j]=max(dp[i][j],M[i][j]+dp[i][k]);*/
                mxc=max(mxc,dp[i][j+2]);
                dp[i][j]=max(dp[i][j],M[i][j]+mxc);
                dp[i][j]=max(dp[i][j],M[i][j]+mxr);
                
                
                /*for(k2=i+2;k2<n;k2++)
                for(k=0;k<m;k++)dp[i][j]=max(dp[i][j],M[i][j]+dp[k2][k]);*/
                mx=max(mx,dp[i][j]);
            }
            
            
        }
        /*fo(i,0,n+2)
        {
           fo(j,0,m+2)cout<<dp[i][j]<<" ";
           cout<<"\n";
        }*/
        cout<<mx<<"\n";
    }
}
int main()
{
    fastio
    solve();
    return 0;
}
