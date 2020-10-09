//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//DP
//SPOJ--> AIBOHP - Aibohphobia
/*
    I ♥ CLARICE STARLING
    EXPLAINATION BELOW->
    Written below in comments
    
    HOW DID I GET THIS THINKING INTO..
    -->As we need a palindrome s[i]==s[(n-1)-i]
    so if now  see the comments near the loops
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define fr(i,b,a) for(i=b;i>a;i--)
#define fre(i,b,a) for(i=b;i>=a;i--)
#define sz(x) (ll)x.size()
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
const int N=(int)1e9;
string s;
vector<vector<int>>dp;
//dp[i][j]-->min number of characters required to answer when consider string part from [i,j]
int recursion(int i,int j)
{
    if(i>=j)return 0;
    if(dp[i][j]!=N)return dp[i][j];
    if(s[i]==s[j])//if these two are same no need to add any character;
    {
        dp[i][j]=min(dp[i][j],recursion(i+1,j-1));
    }
    else //if these are not same then either add s[j] to left of i or add s[i] to right of j
    {
        dp[i][j]=min(dp[i][j],min(1+recursion(i+1,j),1+recursion(i,j-1)));
    }
    return dp[i][j];
}
void solve()
{
    cin>>s;
    dp=vector<vector<int>>(sz(s),vector<int>(sz(s),N));
    recursion(0,sz(s)-1);
    cout<<dp[0][sz(s)-1]<<"\n";
}
int main()
{
    fastio
    Test_cases
    solve();
    return 0;
}
