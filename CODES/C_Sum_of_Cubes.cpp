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
const ll mxn=1e4+5;
unordered_map<ll,ll>mp;
void solve(){
    rep(i,1,mxn){
        ll k=i*1LL*i*i;
        mp[k]++;
    }
}

signed main() {
    FIO;
    ll T=1;cin>>T;
    solve();
    while (T--){
        ll x;cin>>x;
        int fl=0;
        rep(i,1,mxn){
            ll tmp=x-(i*i*i);
            if((i*i*i)>x){break;}
            if(mp.count(tmp)==1){
                fl=1;
                break;
            }
        }
        if(fl==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;   
}