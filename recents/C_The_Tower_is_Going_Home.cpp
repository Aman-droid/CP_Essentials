#include<bits/stdc++.h>
#define ll long long
#define int long long 
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

const int mxn=2e5;

void solve(){
    int n,m,x,x1,x2,y;cin>>n>>m;
    int tot=m+n;
    int ans=tot,tmp=0;
    vector<int>ver,hor;
    rep(i,0,n-1){
        cin>>x;
        ver.pb(x);
    }
    ver.pb(1e9);
    rep(i,0,m-1){
        cin>>x1>>x2>>y;
        if(x1==1){
            hor.pb(x2);
        }
    }
    sort(all(ver));
    sort(all(hor));
    int M=SZ(hor);
    int hr=0,vr=0;
    rep(i,0,n){
        vr=i;
        x=ver[i];
        //watch(x);

        auto it = lower_bound(all(hor),x)-hor.begin();
        //watch2(x,it);        
       
        hr=M-it;
        tmp = (vr+hr); 
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;        
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}