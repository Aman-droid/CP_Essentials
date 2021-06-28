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
void solve(){
    ll n,H;cin>>H>>n;
    ll d[n+1];
    d[0]=0;
    ll ans=1e18;
    rep(i,1,n){
        cin>>d[i];
        d[i]=-d[i];
        d[i]+=d[i-1];
        if(d[i]>=H){
            ans=min(ans,i);
        }
    }
    if(ans<=n){
        cout<<ans<<endl;
        return;
    }
    if(d[n]<=0){
        cout<<-1<<endl;
        return;
    }
    rep(i,1,n){
        ll tmp=(H-d[i])/d[n];
        if(tmp*d[n]+d[i]<H){
            tmp++;
        }
        ans=min(ans,tmp*n+i);
    }
    cout<<ans<<endl;
    return;
}

signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        solve();
    }
    return 0;   
}