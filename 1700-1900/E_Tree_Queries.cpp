#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5+5;
int timer;
int p[mxn], dis[mxn];
int in[mxn], out[mxn];
vector<int> adj[mxn];

void dfs(int node, int par = -1, int dep = 0) {
	p[node] = par;
	dis[node] = dep;
    in[node] = timer++;
	for (auto child : adj[node]) {
		if (child == par) 
            continue;
		dfs(child, node, dep + 1);
	}
	out[node] = timer++;
}

bool checkpar(int v, int u) {
	return in[v] <= in[u] && out[u] <= out[v];
}

void solve(int T){  
    int n, m;cin>>n>>m;
	timer = 0;
    rep(i,1,n){
        adj[i].clear();
        in[i]=out[i]=p[i]=dis[i]=0;
    }

	rep(i,1,n-1){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1);
	for (int i = 0; i < m; ++i) {
		int k;cin >> k;
		vector<int> v(k);
        
		for (auto &it : v) {
			cin >> it;
		}

		int u = v[0];//deepest node
		for (auto it : v){ 
            if (dis[u] < dis[it]) 
                u = it;
        }
        
		for (auto &it : v) {
			if (it == u) continue;
			if (p[it] != -1) 
                it = p[it];
		}

		bool ok = true;
		for (auto it : v){ 
            ok &= checkpar(it, u);
        }

		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}