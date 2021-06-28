// 
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;
vector<ll> adj[10001];
ll  vis[10001],in[10001],low[10001];
int timer;

set<ll> arc_points; // set of  unique articulation  points

void dfs(ll node,ll par)
{
    int subtree=0;
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

    for(ll child:adj[node])
    {
        if(child==par)
            continue;
        if(vis[child]==1)   //backedge
        {
            low[node]=min(low[node],in[child]);
        }
        else        //forward edge
        {
            dfs(child,node);
            subtree++;
            low[node]=min(low[node],low[child]);
            if((in[node]<=low[child]) && par!=-1)   //when child is not connected to any ancestor of the node then  node will be articulation point
            {                                      //this condition check whether current subtree will survive or not    
                // watch(node);                     // we will not check for the root node
                  arc_points.insert(node);
            }
        }
    }
    
    if(par==-1 && subtree>1)
    {
        //cout<<"node_par"<<node<<endl;
        arc_points.insert(node);
    }
}

int main()
{
    ll n,m,u,v;
	while(1)
	{
	    cin>>n>>m;
        if(n==0 &&m==0)
            break;
        for(ll i=1;i<=n;i++) {
            adj[i].clear();
            vis[i]=0;
        }
        arc_points.clear();
        timer=1;
        for(ll i=1;i<=m;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(ll i=1;i<=n;i++){
            if(vis[i]==0)
                dfs(i,-1);
        }
        cout<<arc_points.size()<<endl;
	}
	return 0;
}

