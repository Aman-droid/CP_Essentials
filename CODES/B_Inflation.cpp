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
signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
        ll n,k;cin>>n>>k;
        ll a[n],pr[n];
        rep(i,0,n-1)cin>>a[i];
        pr[0]=a[0];
        rep(i,1,n)pr[i]=pr[i-1]+a[i];
        ll req=0;
        for(ll i=n-1;i>=1;i--){
            if((a[i]*100)>(k*pr[i-1])){
                ll tmp=((a[i]*100)-(k*pr[i-1])+k-1)/k;
                req=max(req,tmp);
            }
        }
        cout<<req<<endl;
    }
    return 0;   
}