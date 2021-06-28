#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vi vector< int >
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front

using namespace std;
vector<int> adj[1001];
int vis[1001];
int dis[1001]; //this will store distance of every node from the  node 0;
void dfs1(int node,int d)
{
	vis[node]=1;
	dis[node]=d;
	for(int child:adj[node])
		if(!vis[child])
			dfs1(child,dis[node]+1);
}

int main()
{
	int n , q , u , v;      //n nodes(1,2,3....n)
	cin>>n;

	for(int i=1;i<=n-1;i++)
	cin>>u>>v , adj[u].push_back(v) , adj[v].push_back(u);
	dfs1(1,0);
	cin>>q;
	int ans=0,minm=10000;
	while(q--)
	{
		int x;cin>>x;
		if(dis[x]<minm)
		{
			minm=dis[x];
			ans=x;
		}
		else if(dis[x]==minm && x<ans)
			ans=x;
	}
	cout<<ans;
}
