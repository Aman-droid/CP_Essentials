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
    ll n,h;cin>>n;
    vpll v,slope;
    ll ans=1;

    rep(i,1,n){
        cin>>h;
        v.pb({i,h});
    }

    if(n==2){
        cout<<"1"<<endl;
    }
    else{
        slope.pb(v[0]);
        slope.pb(v[1]);

        ll len=SZ(slope);
        for(ll i=2;i<n;i++){
            while(SZ(slope)>=2){
                double sl1= ((double)slope[len-1].ss-(double)slope[len-2].ss)/((double)slope[len-1].ff-(double)slope[len-2].ff);
                double sl2= ((double)v[i].ss-(double)slope[len-1].ss)/((double)v[i].ff-(double)slope[len-1].ff);
                
                if(sl1<=sl2){
                    slope.pop_back();
                    len--;
                }

                else{
                    break;
                }
            }
            slope.pb(v[i]);
            len++;
            ans=max(ans,abs(slope[len-1].ff-slope[len-2].ff));
        }
        cout<<ans<<endl;
    }
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}