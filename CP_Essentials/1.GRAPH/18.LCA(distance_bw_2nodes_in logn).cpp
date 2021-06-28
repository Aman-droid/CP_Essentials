#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >

#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mod 1000000007
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

using namespace std;
vector<int> adj[1001];
const int maxN=10;  //power of 2  2^10==1024
int level[1001],LCA[1001][maxN+1] ;

void dfs(int node,int lvl,int  par)         //dfs without vis  array only in tree
{
    level[node]=lvl;
    LCA[node][0]=par;
    for(int child:adj[node])
    {
        if(child!=par)
            dfs(child,lvl+1,node);
    }
}

void init(int n)
{
    dfs(1,0,-1);
    for(int  i=1;i<=maxN;i++){
        for(int j=1;j<=n;j++){
            if(LCA[j][i-1]!=-1){
                int par=LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }
    }
}

int getLCA(int a ,int b)
{
    if(level[b]<level[a])
        swap(a,b);          //we want b to be deeper
    int d=level[b]-level[a];
    while(d>0)
    {
        int i=log2(d);
        b=LCA[b][i];
        d=d-(1<<i);
    }
    if(a==b)return a;
    for(int i=maxN;i>=0;i--)
    {
        if(LCA[a][i]!=-1 &&(LCA[a][i] != LCA[b][i]))
        {
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

int main()
{
    //FIO;
	ll T=1;
	while(T--)
	{
        ll n,a,b,q;cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=maxN;j++)
                LCA[i][j]=-1;

        for(int i=1;i<n;i++)        //n-1 edges
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        init(n);        //initialise the sparsh table
        cin>>q;
        while(q--)
        {
            cin>>a>>b;
            cout<<getDist(a,b)<<endl;
        }

	}
	return 0;
}

