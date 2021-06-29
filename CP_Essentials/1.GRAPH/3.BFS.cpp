#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vi vector< int >
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front

using namespace std;
vector<int> adj[1001];
int vis[10001];
int dis[10001];   //this will store distance of every node from the  node 0;
void bfs(int node)
{
    queue<int>q;
    q.push(node);
	vis[node]=1;
	dis[node]=0;

	while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int child : adj[curr]){
            if(!vis[child]){
                q.push(child);
                dis[child]=dis[curr]+1;
                vis[child]=1;
            }
        }
    }
    
}


int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n , m , u , v;      //n nodes(1,2,3....n)
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            adj[i].clear(),vis[i]=0;
         for(int i=1;i<=m;i++)
            cin>>u>>v , adj[u].push_back(v) , adj[v].push_back(u);
        bfs(1);
        cout<<dis[n]<<endl;
           }
	return 0;
}


/*
//-----------------BFS-----------------------
vector<vector<int>> adj;  // adjacency list representation
int n; // number of nodes
int s; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

q.push(s);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
        if (!used[u]) {
            used[u] = true;
            q.push(u);
            d[u] = d[v] + 1;
            p[u] = v;
        }
    }
}



//shortest path restore
if (!used[u]) {
    cout << "No path!";
} else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
}
//

01 BFS ******  O(E)

 We can simply use a normal queue, and append new vertices at the beginning if the corresponding edge has weight 00, 
 i.e. if d[u]=d[v]d[u]=d[v], or at the end if the edge has weight 11, i.e. if d[u]=d[v]+1d[u]=d[v]+1. 
 This way the queue still remains sorted at all time.
 
vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}

*/
