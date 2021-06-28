#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
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

ll n,a[100005];
vector<pll> adj[100005];
ll sz[100005];
ll ans;
//No of subtree of node
void dfs(ll s,ll par=0)
{
	sz[s]=1;
	for(ll i=0;i<adj[s].size();i++)
	{
		pll child=adj[s][i];
		
		if(child.ff==par)continue;
		dfs(child.ff,s);
		sz[s]+=sz[child.ff];
	}
}
void dfs2(ll s,ll par=1,ll mn=0,ll sum=0)
{
	if(sum-mn>a[s]){
		ans+=sz[s];
		return;
	}
	for(ll i=0;i<adj[s].size();i++){
		pll child=adj[s][i];
		if(child.ff==par)continue;
		dfs2(child.ff,s,min(mn,sum+child.ss),sum+child.ss);
	}
}
int main()
{
    FIO;
    ll T=1;
    while(T--)
	{
    	cin>>n;
    	for(ll i=1;i<=n;i++)cin>>a[i];
    	for(ll i=2;i<=n;i++)
    	{
    		ll v,p;
    		cin>>v>>p;
    		adj[v].pb({i,p});
    		adj[i].pb({v,p});
		}
		dfs(1);
		dfs2(1);
		cout<<ans<<endl;
    }
   return 0;
}