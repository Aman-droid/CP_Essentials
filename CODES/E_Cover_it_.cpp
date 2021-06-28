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
const int mxn=2e5;
vector<int>adj[mxn];
int dis[mxn];
void bfs(int node){
    dis[node]=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int child:adj[cur]){
            if(dis[child]==mod){
                dis[child]=dis[cur]+1;
                q.push(child);
            }
        }
    }
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,u,v;cin>>n>>m;
        rep(i,1,n){
            adj[i].clear();
            dis[i]=mod;
        }
        rep(i,0,m-1){
            cin>>u>>v;adj[u].pb(v);adj[v].pb(u);
        }
        bfs(1);
        int ev=0;int od=0;
        rep(i,1,n){
            if(dis[i]%2==0)ev++;
            else od++;
        }
        int x = (min(ev,od)==ev) ? 0:1;
        cout<<min(od,ev)<<endl;
        rep(i,1,n){
            if(dis[i]%2==x){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;   
}