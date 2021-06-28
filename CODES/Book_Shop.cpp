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
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,x;cin>>n>>x;
        int w[n],val[n];
        rep(i,0,n-1)cin>>w[i];
        rep(i,0,n-1)cin>>val[i];
        int dp[n+1][x+1];
        rep(i,0,n){
            rep(j,0,x){
                if(i==0||j==0)dp[i][j]=0;
                else if(w[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-w[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][x];
    }
    return 0;   
}