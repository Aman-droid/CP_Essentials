int n;
const int mxn=2e5;
vector<int> adj[mxn];
int c[mxn];
void dfs(int node) {
    c[node]=1;
    for (int child : adj[node]) {
        if (!c[child])
            dfs(child);
        c[node] += c[child];
  }
}