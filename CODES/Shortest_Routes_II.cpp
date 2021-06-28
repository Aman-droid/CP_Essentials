#include<bits/stdc++.h>
#define ll long long int
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
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

using vi = vector<ll>;
using vvi = vector<vi>;

ll INF = 1e18;

int main() {
    FIO;
    ll n, m, q, u, v, w;
    cin >> n >> m >> q;
    vvi d(n, vi(n, INF));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w, u--, v--;
        if (w < d[u][v]) d[u][v] = d[v][u] = w;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[j][i] = d[i][k] + d[k][j];
    
    while (q--) {
        cin >> u >> v, u--, v--;
        if (u == v) d[u][v] = 0;
        if (d[u][v] == INF) d[u][v] = -1;
        cout << d[u][v] << "\n";
    } 
}