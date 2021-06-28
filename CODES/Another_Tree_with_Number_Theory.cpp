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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
const ll mxn=2e5;
vector<ll>adj[mxn];
unordered_map<pair<ll,ll>,ll,hash_pair>mp;
ll solve(ll node,ll val){
    if(mp.find({node,val})!=mp.end()){
        return mp[{node,val}];
    }
    ll res=0;
    if(SZ(adj[node])==0){
        mp.insert({{node,val},0});
        return 0;//leaf node
    }
    else{
        ll k=SZ(adj[node]);
        if(val%k==0){
            for(auto it:adj[node]){
                res+=solve(it,val/k);
            }
        }
        else{
            mp.insert({{node,val},val});
            return val;
        }
    }
    mp.insert({{node,val},res});
    return res;
}
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        ll n,m,x,v,w;cin>>n;
        ll a[n];
        rep(i,2,n){
            cin>>x;
            adj[x].pb(i);
        }
        ll q;cin>>q;
        while(q--){
            cin>>v>>w;
            ll ans=solve(v,w);
            cout<<ans<<endl;
        }
    }
    return 0;   
}