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
 
// #include<bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define fr(a,b) for(int i = a; i < b; i++)
// #define rep(i,a,b) for(int i = a; i < b; i++)
// #define mod 1000000007
// #define inf (1LL<<60)
// #define all(x) (x).begin(), (x).end()
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll,pair<ll,ll>>
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// using namespace std;
 
vector<int> adj[200001];
int depth[200001];
int ans[200001];
 
void dfs1(int node, int par){
    int src_depth = 0;

    for(int child : adj[node]){
        if(child != par)
        {
            dfs1(child, node);
            src_depth = max(src_depth, 1 + depth[child]);
        }
    }
    depth[node] = src_depth;
}
 
void solve(int node, int par, int par_ans)
{
    vector<int> prefixMax, suffixMax;
    
    // get depth of child nodes.
    for(int child : adj[node])
    {
        if(child != par)
        {
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }
    // build prefix and suffix
    for(int i = 1; i < prefixMax.size(); i++)
        prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);

    for(int i = (int)suffixMax.size() - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
 
    //eval ans for every child c_no
    int c_no = 0;
    for(int child : adj[node])
    {
        if(child != par)
        {
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int op2 = (c_no == (int)suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            int partial_ans = 1 + max(par_ans, max(op1,op2));
 
            solve(child, node, partial_ans);
            c_no++;
        }
    }
 
    //eval ans for src
    ans[node] = 1 + max(par_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
}
 
signed main() {
   FIO;
   int n,m,x,i,j,k,q;
   int T=1;//cin>>T;
   while(T--){
        cin >> n;
        rep(i,1,n-1){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0);
        solve(1, 0, -1);
        
        rep(i,1,n)
            cout << ans[i] <<' ';
   }
   return 0;
}