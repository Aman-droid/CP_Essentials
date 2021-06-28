#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
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
const int mxn=2e5;
vector<int> col(mxn,0), d(mxn,0);       
vector<int> adj[mxn];
 
void dfs(int node, int par)
{
	d[node] = col[node];
	for(int child:adj[node] ){
 
		if (child==par)
			continue;
		dfs(child, node);
		d[node] += d[child];
	}	
}
 
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--)
    {
        int n,x,y,u,v;cin>>n;
        rep(i,1,n-1){
            cin>>u>>v>>x;
            adj[u].pb(v);
            adj[v].pb(u);
            if(x==2){
                col[u]=1;
                col[v]=1;
            }
        }
        dfs(1,-1);
        vector<int> ans;
        rep(i,1,n){
            if(col[i]==1 && d[i]==1)
                ans.pb(i);
        }
        cout<<SZ(ans)<<endl;
        for(int i=0;i<SZ(ans);i++){
                cout<<ans[i]<<" ";
        }

    }
}

