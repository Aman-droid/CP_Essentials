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

const int maxn = 100005;
vector <int> adj[maxn];
vector <int> tg[maxn];
bool vis[maxn];
stack <int> st;
ll minm = INT_MAX;
ll cnt = 1;
ll w[maxn];


void Rdfs(int node)
{
    if (w[node] < minm){minm = w[node]; cnt = 1;}
    else if (w[node] == minm){cnt++;}
    vis[node]=1;
    for (auto child:tg[node])
    {
        if (!vis[child])
        {
            Rdfs(child);
        }
    }
}

void dfs(int node)
{
    vis[node] = 1;
    for (auto it:adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    st.push(node);
}

int main()
{
    FIO;
    ll n, m, ans = 0, res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++){cin >> w[i];}
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;cin >> a >> b;
        tg[b].push_back(a);     //Transpose graph
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    rep(i,1,n)
        vis[i]=0;
    while(!st.empty())
    {
        int nd = st.top();
        st.pop();
        if(!vis[nd])
        {
            minm = INT_MAX;
            cnt = 1;
            Rdfs(nd);
            ans += minm;
            res *= cnt;
            res = res %mod;
        }
    }
    cout <<ans <<" "<<res << endl;
    return 0;
}
