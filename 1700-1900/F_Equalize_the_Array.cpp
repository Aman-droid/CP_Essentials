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

//--------------------------------------------------------------------------------------------------------//
const ll mxn=3e5;
// ll vec[mxn];
// ll pr[mxn];
// unordered_map<ll,ll>mp;
signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
        ll n,x,y;cin>>n;
        map<ll,ll>mp;
        vector<ll>vec;
        rep(i,1,n){
            cin>>x;
            mp[x]++;
        }
        for(auto it :mp){
            vec.pb(it.ss);
        }
        sort(vec.begin(),vec.end());
        ll ans=1e12;
        for(ll c:vec){
            ll s=lower_bound(vec.begin(),vec.end(),c)-vec.begin();
            ll h=SZ(vec)-s;
            ans=min(ans,(n-c*h));
        }
        cout<<ans<<endl;
        mp.clear();
    }
    return 0;   
}