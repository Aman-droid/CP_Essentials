/*
    calculate ans for the node
    then calculating ans for the child using ans of the parent 
    using rerooting and calculating partial answers

*/

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
const int mxn=200001; 
vector<int> adj[mxn];
ll subtreeAns[mxn];
ll ans[mxn];
int subtreeSize[mxn];
 
void dfs1(int node, int par)
{
    int numOfNodes = 1;
    int ansForSubtree = 0;
 
    for(int child : adj[node])
    {
        if(child != par)
        {
            dfs1(child, node);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[node] = numOfNodes;
    subtreeAns[node] = ansForSubtree;
}
 
void dfs2(int src, int par, ll par_ans, int& totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : adj[src])
    {
        if(child != par)
            dfs2(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
 
signed main() {
    FIO;
    int n,T=1,u,v;
 
    while(T--){
        cin >> n;
        rep(i,1,n-1)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0); //in ans for every node..preprocessing
        dfs2(1, 0, 0, n);
        
        rep(i,1,n)
            cout << ans[i] <<' ';
    }
    return 0;
}
