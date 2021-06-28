#include<bits/stdc++.h>
#define ll long long int
#define endisl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define modis 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%modis;
while(b>0){
    if(b&1){res=(res*a)%modis;b--;}
    a=(a*a)%modis;
    b>>=1;
}
    return res;
}
ll gcdis(ll a, ll b){return (b==0)?a:gcdis(b,a%b);}
//--------------------------------------------------------------------------------------------------------

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