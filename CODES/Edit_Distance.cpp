#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//
 
int solve(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    rep(i,0,m) {
        rep(j,0,n) {
            if (i == 0)
                dp[i][j] = j; // Min. opr =j
            else if (j == 0)
                dp[i][j] = i; // Min. opr = i
 
            // If last characters are same
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
 
            // all possibilities and find the minimum
            else
                dp[i][j]= 1+ min(dp[i][j - 1],min (dp[i - 1][j], dp[i - 1][j - 1])); // Insert // Remove // Replace
        }
    }
    return dp[m][n];
}
 
int main()
{
    string s1,s2;cin>>s1>>s2; 
    int m=s1.length();
    int n=s2.length();
    int ans=solve(s1,s2,m,n);
    cout<<ans<<endl;
 
    return 0;
}