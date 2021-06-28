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
        ll n,m,x;cin>>n;
        ll a[n],b[n],c[n];
        rep(i,0,n-1){cin>>c[i];}
        rep(i,0,n-1){cin>>a[i];}
        rep(i,0,n-1){cin>>b[i];}
        ll tmp=0,ans=0;
        rep(i,1,n-1){
            if(a[i]==b[i]){
                tmp=0;
            }
            else{
                tmp=max(abs(b[i]-a[i]),tmp-abs(b[i]-a[i]));
            }
            tmp+=2;
            tmp+=c[i]-1;
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;   
}