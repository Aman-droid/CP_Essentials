#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
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

const int mxn = 2e5;
int n;
int c[mxn];
vector<int>adj[mxn];

void dfs(int node) {
    c[node]++;
    for (int child : adj[node]) {
        if (!c[child])
            dfs(child);
        c[node] += c[child];
  }
}

int main() {
    int u;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u;
        u--;
        adj[u].push_back(i);
    }
    for (int i = 0; i < n; i++)
        if (!c[i])
            dfs(i);
    
    for (int i = 0; i < n; i++)
    cout << c[i] - 1 <<" ";
}