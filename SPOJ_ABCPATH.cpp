//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//DP on Graph
//SPOJ--> ABCPATH - ABC Path
/*
    I ♥ CLARICE STARLING
    EXPLAINATION BELOW->
    1)dp[i][j]-->Starting from i,j what is longest possible consecutive length of characters..
    2)
     Ex-->
         A
         \
         B
        / \
      C    C
      \    |
      D    D
      |    /
      |   /
      | /
      |/
      E-->You can see here for this E(i,j) this state will checked twice in recursion tree so Overlapping subproblems 
    / \  
   Z  F
      \
      G
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
#define all(x) x.begin(),x.end()
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
int n,m,ans,idx;
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
vector<vector<int>>M,dp;
vector<vector<bool>>visited;
bool check(int x,int y)
{
    return ((x>=0&&x<n)&&(y>=0&&y<m)&&(visited[x][y]==false));
}
int dfs(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    visited[x][y]=true;
    int i;
    fo(i,0,8)
    {
        int x1,y1;
        x1=x+dx[i];y1=y+dy[i];
        if(check(x1,y1)&&(M[x1][y1]-M[x][y]==1))
        {
            dp[x][y]=max(dp[x][y],dfs(x1,y1)+1);
        }
    }
    if(dp[x][y]==-1)dp[x][y]=0;
    return dp[x][y];
}
void solve()
{
    while(true)
    {
        ans=0;
        idx++;
        cin>>n>>m;
        if(!(n|m))break;
        M=dp=vector<vector<int>>(n,vector<int>(m,-1));
        visited=vector<vector<bool>>(n,vector<bool>(m,false));
        char c;
        int i,j;
        fo(i,0,n)fo(j,0,m){cin>>c;M[i][j]=c-'A';}
        
        int f=0;
        fo(i,0,n)
        fo(j,0,m)
        {
            if(M[i][j]==0)ans=max(ans,dfs(i,j)),f=1;
        }
        if(f==0)ans=-1;
        cout<<"Case "<<idx<<": "<<ans+1<<"\n";
    }
}
int main()
{
    fastio
    solve();
    return 0;
}
