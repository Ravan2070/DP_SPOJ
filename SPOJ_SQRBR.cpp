//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//SPOJ SQRBR - Square Brackets
//DP
/*
    Hint:-->You can place an opening bracket at position i if the number of blanks
    after position i > 0
    preblank==>(lastpos)-(pos)-2*(number of brackets already placed)
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
vector<char>s;
vector<vector<ll>>dp;
int n,k;
//dp[pos][cnt]-->number of ways to place '[' such that cur position is pos (i.e considering [pos..2*n-1]) and already cnt '[' brackets are placed
ll recursion(int pos,int cnt)
{
    int preblank=((2*n-1)-pos)-2*cnt;
    
   
    if(pos<0)
    {
        if(cnt!=n)return 0ll;
        else return 1ll;
    }
    if(dp[pos][cnt])return dp[pos][cnt];
    ll ans=0ll;
    if(s[pos]=='[')
    {
       if(preblank==0)ans=0ll;
       else ans=recursion(pos-1,cnt+1); 
    }
    else {
    
        if(preblank>0)
        {
            ans=(recursion(pos-1,cnt+1)+recursion(pos-1,cnt));
        }
        else 
        {  
            ans=recursion(pos-1,cnt);
        }
    }
    dp[pos][cnt]=ans;
    return dp[pos][cnt];
}
void solve()
{
 int i,t;cin>>n>>k;
 s=vector<char>(n*2,'_');
 fo(i,0,k)
 {
     cin>>t;
     s[--t]='[';
 }
 dp=vector<vector<ll>>(n*2,vector<ll>(n,0ll));
 recursion(2*n-1,0);
 cout<<dp[2*n-1][0]<<"\n";
 
 
}
int main()
{
   fastio
   Test_cases
   solve();
  return 0;
}
