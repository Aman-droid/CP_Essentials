#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vi vector< int >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front

using namespace std;
vector<int> adj[100001];
int vis[100001];      //we define globally  int array then initial values are zero..

void dfs(int node)
{
	vis[node] = 1;

	for(int child : adj[node])
	if(!vis[child])
	dfs(child);
}


int main()
{
	int n , m , u , v;      //n nodes(1,2,3....n)
	cin>>n>>m;          // m edges

	for(int i=1;i<=m;i++)
	cin>>u>>v , adj[u].push_back(v) , adj[v].push_back(u);

	int cc_count = 0;
	for(int i=1;i<=n;i++)
	if(!vis[i])
	dfs(i) , cc_count++;

	cout<<cc_count;
}
