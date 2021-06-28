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
const ll mxn=3e6;
ll spf[mxn];
ll c[mxn];
ll mp[mxn];
void sieve(){
    spf[0] = spf[1] = 1;
    for (int i = 2; i < mxn; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < mxn; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
            spf[i] = i;
        }
    }
}
void init(){
    ll cnt=0;
    for(ll i=2;i<=mxn;i++){
        if(spf[i]==i){
            cnt++;
            mp[i]=cnt;
        }
    }
}
int main() {
    FIO;
    sieve();
    init();
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        vector<ll>ans;
        rep(i,0,2*n-1){
            cin>>x;
            c[x]++;
        }
        for(ll i=mxn-1;i>=0;i--){
            if(c[i]==0)continue;
            while(c[i]>0){
                if(spf[i]==i){
                    x=mp[i];
                    ans.pb(x);
                    c[x]--;
                }
                else{
                    x=i/spf[i];
                    ans.pb(i);
                    c[x]--;
                }
                c[i]--;
            }
        }
        rep(i,0,SZ(ans)-1){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
    return 0;   
}