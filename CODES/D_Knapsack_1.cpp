#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
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
void knapsack(ll a[],ll w[],ll n,ll W){
    ll dp[n+1][W+1];
    rep(i,0LL,n){
        rep(j,0LL,W){
            if(i==0 ||j==0)dp[i][j]=0;
            else if(w[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+a[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W];
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,W;cin>>n>>W;
        ll a[n],w[n];
        rep(i,0,n-1){cin>>w[i]>>a[i];}
        knapsack(a,w,n,W);
    }
    return 0;   
}