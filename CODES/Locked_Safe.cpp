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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const ll mxn=2e5;

void solve(){
    ll n;cin>>n;
    ll mx=-1;
    ll a[n];
    rep(i,0,n-1){
        cin>>a[i];
        mx=max(a[i],mx);
    }

    vector<ll>res1,res2;
    ll cur = a[0];
    ll cnt=0;
    rep(i,0,n-1){
        if(a[i]==cur){
            cnt++;
        }
        else{
            if(cnt>0){
                res1.pb(cnt);
            }
            cnt=1;
            cur=a[i];
        }
    }
    if(cnt>0){
        res1.pb(cnt);
    }
    ll sum1=0,sum2=0;
    for(auto it:res1){
       // cout<<it<<" " ;
        sum1+=(it*(it+1))/2;    
    }
    ll ans=(n*(n+1))/2 - sum1;
    cout<<ans<<endl;
    return;
}

signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}