#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
const int mxn=3e5;
//vector<ll>adj[mxn];
ll d[mxn],w[mxn];

int main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,m,u,v;cin>>n;
        ll sum=0;
        rep(i,1,n){
            //adj[i].clear();
            //vis[i]=0;
            d[i]=0;
            cin>>w[i];
            sum+=w[i];
        }
        rep(i,1,n-1){
            cin>>u>>v;
            //adj[u].pb(v);
            //adj[v].pb(u);
            d[u]++;
            d[v]++;
        }
        priority_queue<pair<ll,ll>>q;
        rep(i,1,n){
            if(d[i]>1)
                q.push({w[i],d[i]});
        }
        cout<<sum<<" ";
        while(!q.empty()){
            pll p=q.top();
            for(ll i=2;i<=p.ss;i++){
                sum+=p.ff;
                cout<<sum<<" ";
            }
            q.pop();
        }
        cout<<endl;
    }
    return 0;   
}