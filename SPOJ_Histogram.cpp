//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//DP+Bitmasking+TSP
//SPOJ--> HIST2 - Histogram
/*
    I ♥ CLARICE STARLING
    EXPLAINATION BELOW->
    Same as TSP dp approach;
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
const int N=17;
const int MASK=(1<<N);
int fullmask,n;
int dp[N][MASK];
int count1[N][MASK];
vector<int>a;
//dp[lastvisited][mask]-->when starting from a fixed i and ending at pos,visiting all indices set in mask exactly once what is max possible value obtained
int recursion(int lastvisited,int mask)
{
    if(dp[lastvisited][mask]!=-1)return dp[lastvisited][mask];
    int val=0;
    int notvisited;
    fo(notvisited,0,n)
    {
        if((mask&(1<<notvisited))==0)
        {
           if((mask|(1<<notvisited))==fullmask)
           {
              dp[lastvisited][mask]=abs(a[notvisited]-a[lastvisited])+a[notvisited];
              count1[lastvisited][mask]=1;//pretty obvious as this subproblem has only 2 elements under consideration
           }
           else
           {
               val=recursion(notvisited,mask|(1<<notvisited))+abs(a[notvisited]-a[lastvisited]); 
               if(val>dp[lastvisited][mask])
               {
                   dp[lastvisited][mask]=val;
                   count1[lastvisited][mask]=0;
               }
               
               if(dp[lastvisited][mask]==val)count1[lastvisited][mask]+=count1[notvisited][mask|(1<<notvisited)];
           }
        }
    }
    return dp[lastvisited][mask];
}
void solve()
{
    while(true)
    {
        int i;cin>>n;
        if(n==0)return;
        fullmask=(1<<n)-1;
        memset(dp,-1,sizeof(dp));
        memset(count1,0,sizeof(count1));
        a=vector<int>(n);
        fo(i,0,n)cin>>a[i];
        
        int ans,cnt,mx;
        ans=cnt=mx=0;
        fo(i,0,n)
        {
            ans=max(ans,recursion(i,(1<<i))+a[i]);
            if(ans>mx)
            {
               mx=ans;
               cnt=count1[i][(1<<i)];
            }
            else if(ans==mx)cnt+=count1[i][(1<<i)];
        }
        cout<<mx+2*n<<" "<<cnt<<"\n";
    }
}
int main()
{
    fastio
    solve();
    return 0;
}
