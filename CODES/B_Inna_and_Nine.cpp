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
const ll mxn=2e5;
ll L[mxn];
ll R[mxn];
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        string s;cin>>s;
        ll n=SZ(s); 
        ll len;
        ll ans=1;
        rep(i,1,n-1){
            len=1;
            while((s[i-1]-'0')+(s[i]-'0')==9  && i<n ){
                i++;
                len++;
            }
            if(len%2==1){
                ans=ans*((len+1)/2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;   
}