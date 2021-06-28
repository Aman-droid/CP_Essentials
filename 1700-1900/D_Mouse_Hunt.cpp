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
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5 +5; //check :(
int n, cost[mxn], a[mxn], vis[mxn];
ll ans = 0;
vector<int> cyc;
 
void dfs(int x) {
    vis[x] = 1;
    if(vis[a[x]] == 0) {
        dfs(a[x]);
    }
    else if(vis[a[x]] == 1) {
        cyc.push_back(a[x]);
    }
    vis[x] = 2;
}
 

void solve(){
    cin >> n;
    rep(i,1,n)cin>>cost[i];
    rep(i,1,n)cin>>a[i];

    rep(i,1,n){
        if(vis[i] == 0) {
            dfs(i);
        }
    }

    for(int node : cyc) {
        int mn = cost[node];
        int par = a[node];

        while(par != node) {
            mn = min(mn, cost[par]);
            par = a[par];
        }
        ans += mn;
    }
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}