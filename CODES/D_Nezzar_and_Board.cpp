#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
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
        ll n,k,x;cin>>n>>k;
        ll a[n];
        rep(i,0,n-1){cin>>a[i];} // y and 2x-y are mirror image about x  every mod|y-x| is possible  
        ll tmp=a[0];
        rep(i,0,n-1){
            a[i]-=tmp;
        }
        k-=tmp;
        ll gc=0;
        rep(i,0,n-1){
            gc=gcd(gc,abs(a[i]));
        }
        string ans;
        ans=(k%gc==0)?"YES":"NO";
        cout<<ans<<endl;
    }
    return 0;   
}
