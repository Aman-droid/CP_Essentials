#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
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
ll n,m;
vector<ll> adj[200005];
ll deg[200005], vis[200005];
vector<pll>ans;

void bfs(ll node){
	queue<ll>q;
	q.push(node);
	vis[node]=1;
	while(!q.empty()){
		ll cur=q.front();
		q.pop();
		for(int child:adj[cur]){
			if(vis[child]==1)continue;
			ans.pb({cur,child});
			q.push(child);
			vis[child]=1;
		}
	}
}
int main()
{
	//FIO;
	int T=1;
	while(T--) {
		cin>>n>>m;
		for(ll i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			u--;v--;
			adj[u].pb(v);
            adj[v].pb(u);
			deg[u]++;deg[v]++;
		}
		ll pos=0;
		for(ll i=0;i<n;i++){
			if(deg[pos]<deg[i])pos=i;
		}
		bfs(pos);
		for(ll i=0;i<ans.size();i++)
            cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
	}
}
 