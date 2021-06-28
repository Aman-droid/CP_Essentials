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
const ll mxn=2e4;
ll inv(ll a){
    return power(a,mod-2);
}

ll fac[mxn];
ll inr[mxn];
void fact(){
	fac[0]=1;
	for(ll i=1;i<mxn;i++)fac[i]=(fac[i-1]*i)%mod;
	inr[0]=1;
	for(ll i=1;i<mxn;i++)inr[i]=inv(fac[i]);
}

ll ncr(ll n,ll r){
	ll a=(fac[n]*inr[r])%mod;
	ll b=(a*inr[n-r])%mod;
	return b;
}

signed main() {
    FIO;
    fact();
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n>>m;
        ll k=(2LL*m)+n-1LL;
        ll ans=ncr(k,n-1LL);
        cout<<ans<<endl;
    }
    return 0;   
}