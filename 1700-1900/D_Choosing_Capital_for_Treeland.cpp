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

const int mxn=2e5+5;
vector<int>adj[mxn];
int vis[mxn];
int d[mxn],up[mxn];

map<pair<int,int>,int>mp;
int tot_up=0;

void bfs(int node){
    up[node]= 0;
    vis[node]=1;
    d[node]=0;

    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int child:adj[cur]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);

                d[child] = d[cur]+1;
                up[child] += up[cur];

                if(mp.count({child,cur})){
                    up[child]++;
                    tot_up++;
                }
            }
        }
    }
}   
void solve(){
    int n,x,u,v;cin>>n;
    rep(i,1,n-1){
        cin>>u>>v;//u-->v
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u,v}]++;
    }

    bfs(1);
    int ans[n+1];
    int mn=INF;
    rep(i,1,n){
        int up_path = up[i]; 
        ans[i]= tot_up -(up[i]) + (d[i]-up[i]);
        mn=min(mn,ans[i]);
    }

    // rep(i,1,n)cout<<d[i]<<" ";cout<<endl;
    // rep(i,1,n)cout<<up[i]<<" ";cout<<endl;
    // rep(i,1,n)cout<<ans[i]<<" ";cout<<endl;
    
    cout<<mn<<endl;
    rep(i,1,n){
        if(ans[i]==mn){
            cout<<i<<" ";
        }
    }
    cout<<endl;


}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}