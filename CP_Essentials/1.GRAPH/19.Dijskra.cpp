// Time complexity : O(ElogV)
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;


const int mxn=2e5;
const int INF= 1e15;

vector<pair<int,int>> G[mxn];  //Graph
vector<int> Dist;  // for storing the distance of every other node from source.
vector<int> par;  // for storing the distance of every other node from source.
/*==========================================*/
void Dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
    Dist.assign(N,INF);
    par.assign(N,-1);

    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.first;
            int w = c.second;
            if(Dist[v] > Dist[u]+w){
                Dist[v] = Dist[u]+w;
                par[v]=u;
                Q.push({Dist[v],v});
            }
        }
    }
}
/*===========================================*/
int main() {
    int N, M, u, v, w, source;  // N-total no of nodes, M-no. of edges, 
    cin >> N >> M;              // u,v and w are the end vertices and the weight associated with an edge
    
    for(int i=0;i<M;++i){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    cin >> source;

    Dijkstra(source,N);
    
    for(int i=0;i<N;i++)
        cout<<Dist[i]<<" ";
    cout<<endl;
    
    return 0;
}

/*
//USING TUPLES
using ii = tuple<ll, ll>;   //
using vii = vector<ii>;     //vector of tuples
using qii = priority_queue<ii, vii, greater<ii>>; //min heap lowest dis node on the top 

int main() 
{
    FIO;
    ll n, m, u, v, w, y;cin >> n >> m;
    vector<vii> adj(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    vector<ll> dis(n, 1000000000LL * m + 1LL), vis(n);
    dis[0] = 0;
    qii q;
    q.push({0, 0});
    while (!q.empty()) {
        tie(w, u) = q.top();   //w=weight and u = node
        q.pop();                //tie used to unpack the tuple into variables
        if (vis[u]) continue;
        vis[u] = 1;
        for (ii child : adj[u]) {
            tie(v, y) = child;          //v=node and y = weight of edge
            if (dis[u] + y < dis[v]) {
                dis[v] = dis[u] + y;
                q.push({dis[v], v});
            }
        }
    } 
    for (int i = 0; i < n; i++)
        cout << dis[i] << " \n"[i == n - 1];
}
*/

//PATH print
// vector<int> restore_path(int s, int t, vector<int> const& p) {
//     vector<int> path;

//     for (int v = t; v != s; v = p[v])
//         path.push_back(v);
//
//     path.push_back(s);

//     reverse(path.begin(), path.end());
//     return path;
// }