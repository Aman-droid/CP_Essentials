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
const ll mxn=2e5+1;
vector<pair<ll,ll>>ans;
int vis[mxn];

bool chk(ll a[],ll mx,ll n){
    int fl=0;
    rep(i,1,n){
        vis[i]=0;
    }
    rep(i,1,mx){
        vis[a[i]]=1;
    }
    rep(i,1,mx){
        if(vis[i]==0){
            fl=1;
            break;
        }
    }

    rep(i,1,n){
        vis[i]=0;
    }
    rep(i,mx+1,n){
        vis[a[i]]=1;
    }
    rep(i,1,n-mx){
        if(vis[i]==0){
            fl=1;
            break;
        }
    }
    if(fl==1)return false;
    else return true;
}
void solve(){
    ll n;cin>>n;
    ll x,a[n+1];
    ll mx=-1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    if(chk(a,mx,n)){
        ans.pb({mx,n-mx});
    }
    if(chk(a,n-mx,n) && mx*2!=n){
        ans.pb({n-mx,mx});
    }
    cout<<SZ(ans)<<endl;
    for(auto it:ans){
        cout<<it.ff<<" "<<it.ss;
        cout<<endl;
    }
    ans.clear();
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}