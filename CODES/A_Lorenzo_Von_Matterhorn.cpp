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
unordered_map<ll,ll>mp;
ll ans=0;
void LCA(ll v,ll u,ll w){
    
    while(v!=u){
        if(v<u)swap(u,v); //v greater
        mp[v]+=w;
        v=v/2;
    }   
}
ll LCA_2(ll v,ll u){
    ll sum=0;
    while(u!=v){
        if(v<u) swap(u,v); //v greater
        if(mp.find(v)!=mp.end()){
            sum+=mp[v];
        }
        v=v/2;
    }
    return sum;   
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll x,u,v,w;cin>>x;
        if(x == 1){
            cin>>v>>u>>w;
            LCA(v,u,w);
        }
        else{
            cin>>v>>u;
            ans=LCA_2(v,u);
            cout<<ans<<endl;   
        }
    }
    return 0;   
}