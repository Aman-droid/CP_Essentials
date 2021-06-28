
// create in[] and low[] arrays..
// node having lower intime is ancestor........
// forward edge = part of the dfs
// back edge = (child=visited and not parent ) =>update node of back edge min()..
//bridge ==edgw whwn removed make graph disconnected

#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define mod 1000000007
using namespace std;

vector<int> adj[1000001];
int  vis[1000001],in[1000001], low[1000001];
int timer;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

    for(int child:adj[node])
    {
        if(child==par)
            continue;
        if(vis[child]==1)     //edge node-child node is back edge
        {
            low[node]= min(low[node],in[child]); //minimize the node with child....
        }
        else
        {
            dfs(child,node);   //edge node -child node is forward edge
            //if low[child] < in[node] -=>means node -child is not a bridhge and child is already connected to
            //to one of its ancester so removing this edge will not make grapg disconnected

            if(low[child] > in[node])
                cout<<node<<"--"<<child<<"is a bridge"<<endl;
                 
            low[node]=min(low[node],low[child]);
        }
    }
  
}
int main()
{
    int n ,m, u , v,x,y;      //n nodes(1,2,3....n)
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>u>>v , adj[u].push_back(v) , adj[v].push_back(u);
    dfs (1,-1);
	return 0;
}


