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
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,q,k,l,r;cin>>n>>q>>k;
        ll a[n+1];
        rep(i,1,n){
            cin>>a[i];
        }
        while(q--){
            cin>>l>>r;
            ll len=r-l+1;
            ll nos=a[r]-a[l]+1;
            ll ans=0;
            if(len==nos){
                ans+=a[l]-1LL;
                ans+=k-a[r];
                cout<<ans<<endl;
            }
            else{
                ll dif=nos-len;
                ans+=dif*2LL;
                ans+=a[l]-1LL;
                ans+=k-a[r];
                cout<<ans<<endl;
            }
        }

    }
    return 0;   
}