//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//MBLAST - BLAST
//Edit-distance variation
//https://www.spoj.com/problems/MBLAST/
/*                                                    
      I ♥ CLARICE STARLING...                                                               
        EXPLAINATION BELOW->
*/
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
const int N=(int)2e3+1;
int k;
string a,b;
int dp[N][N];
int edit_distance(int i,int j)
{
    
    if(i==-1)return (j+1)*k;
    if(j==-1)return (i+1)*k;
    if(dp[i][j]!=1e9)return dp[i][j];
    
    dp[i][j]=min(dp[i][j],min((abs(a[i]-b[j])+edit_distance(i-1,j-1)),min(k+edit_distance(i-1,j),k+edit_distance(i,j-1))));
    return dp[i][j];
}
void solve()
{
   cin>>a>>b;
   cin>>k;
   int i,j;
   fo(i,0,N)fo(j,0,N)dp[i][j]=1e9;
   cout<<edit_distance(sz(a)-1,sz(b)-1)<<"\n";
}
int main()
{
   fastio
   //Test_cases
   solve();
  return 0;
}
//map<ll,ll,greater<int>> to sort in descending order ,in iterator declaration no greater<int>
//if you want to apply lowerbound on set use s.lower_bound(key),not the one used for vector
// Syntax to create a min heap for priority queue priority_queue <int, vector<int>, greater<int>>; 
//for modinverse use modularexponention(x,M-2,M);
//for "each" subtraction from ans(ans-k) if(ans<0) do ans+=MOD,ans%=MOD
//vector<vector<int>>dp(201,vector<int>(n+1)); A way to initialize vector of vector
//string2=string1.substr(pos,length);if len no specified then till end
//void fill (ForwardIterator first, ForwardIterator last, const T& val);
//The range filled is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.


//If wrong on pretest 2 means logically wrong
/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
