#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
const int mxn=3e5,mxN=20;
vector<int> adj[mxn];
int level[mxn],LCA[mxn][mxN+1] ;

void dfs(int node,int lvl,int  par){
    level[node]=lvl;
    LCA[node][0]=par;
    for(int child:adj[node]){
        if(child!=par)
            dfs(child,lvl+1,node);
    }
}

void init(int n){
    dfs(1,0,-1);
    for(int  i=1;i<=mxN;i++){
        for(int j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1){
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }
    }
}

int getLCA(int a ,int b){
    if(level[b]<level[a])
        swap(a,b);          //we want b to be deeper
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=LCA[b][i];
        d=d-(1<<i);
    }
    if(a==b)return a;
    for(int i=mxN;i>=0;i--){
        if(LCA[a][i]!=-1 &&(LCA[a][i] != LCA[b][i])){
            a=LCA[a][i];
            b=LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDist(int a,int b)
{
    int lca=getLCA(a,b);
    int ans =level[a]+level[b]-(2*level[lca]);
    return ans;
}

int main(){
    //FIO;
	ll T=1;
	while(T--)
	{
        ll n,a,b,q;cin>>n>>q;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=mxN;j++)
                LCA[i][j]=-1;

        for(int i=2;i<=n;i++){    
            cin>>a>>b;adj[a].pb(b);adj[b].pb(a);
        }
        init(n);        //initialise the sparsh table
        while(q--){
            cin>>a>>b;
            cout<<getDist(a,b)<<endl;
        }
	}
	return 0;
}