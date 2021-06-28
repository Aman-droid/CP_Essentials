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
int n,k,u,v;
vector<int>grp[mxn];
vector<pii>tmp,ans;
int vis[mxn];
int cnt=0;
 
bool comp(pii a,pii b){
    if(a.ff!= b.ff){
        return a.ff > b.ff;
    }
    else{
        return a.ss > b.ss;
    }
}

class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency list
    list<int> *adj;
 
    // Vector to store indegree of vertices
    vector<int> indegree;
 
    // A function used by alltopologicalSort
    void alltopologicalSortUtil(vector<int>& res,
                                bool visited[]);
 
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints all Topological Sorts
    void alltopologicalSort();
};
 
//  Constructor of graph
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
 
    // Initialising all indegree with 0
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}
 
//  Utility function to add edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
 
    // increasing inner degree of w by 1
    indegree[w]++;
}
 
//  Main recursive function to print all possible
//  topological sorts
void Graph::alltopologicalSortUtil(vector<int>& res,
                                   bool visited[])
{
    // To indicate whether all topological are found
    // or not
    bool flag = false; 
 
    for (int i = 0; i < V; i++)
    {
        //  If indegree is 0 and not yet visited then
        //  only choose that vertex
        if (indegree[i] == 0 && !visited[i])
        {
            //  reducing indegree of adjacent vertices
            list<int>:: iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]--;
 
            //  including in result
            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited);
 
            // resetting visited, res and indegree for
            // backtracking
            visited[i] = false;
            res.erase(res.end() - 1);
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;
 
            flag = true;
        }
    }
 
    //  We reach here if all vertices are visited.
    //  So we print the solution here
    if (!flag)
    {
        //watch(SZ(res));
        // for (int i = 0; i < res.size(); i++)
        //     cout << res[i] << " ";
        // cout << endl;
        cnt++;
    }
}
 
//  The function does all Topological Sort.
//  It uses recursive alltopologicalSortUtil()
void Graph::alltopologicalSort()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    vector<int> res;
    alltopologicalSortUtil(res, visited);
}

// graph formation
void dfs(int node){
    vis[node]=1;
    for(int child:grp[node]){
        if(vis[child]==0){
            tmp.pb({child,node});
            dfs(child);
        }
    }
}


signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ans.clear();
        cin>>n>>k;
        rep(i,1,n-1){
            cin>>u>>v;
            u--;
            v--;
            grp[u].pb(v);
            grp[v].pb(u);
        }
        if(n==1){
            cout<<"1"<<" "<<"1"<<endl;
            continue;
        }
        else if(n==2){
            if(k==1){
                cout<<"1"<<" "<<"2"<<endl;
            }
            else{
                cout<<"1"<<" "<<"1"<<endl;
            }
            continue;     
        }
        rep(i,0,n-1){
            tmp.clear();
            cnt=0;
            rep(j,0,n-1)vis[j]=0;
            Graph g(n);
            dfs(i);
            for(auto it:tmp){
                //watch2(it.ff,it.ss);
                g.addEdge(it.ff,it.ss);
            }
            //cout << "All Topological sorts\n";
            g.alltopologicalSort();
            //cout<<cnt;
            ans.pb({cnt,i+1});
        }
        //sort(all(ans),comp());
        sort(ans.begin(),ans.end(),comp);
        // for(auto it:ans){
        //     cout<< it.ss <<" "<<it.ff<<endl;
        // }
        if(k==1){
            cout<<ans[0].ss<<" "<<ans[0].ff<<endl;
        }
        else{
            cout<<ans[1].ss<<" "<<ans[1].ff<<endl;
        }
    }
    return 0;   
}