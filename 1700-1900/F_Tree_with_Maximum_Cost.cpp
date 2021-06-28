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
const int mxn=2e5+5; 
int total;
vector<int> a,sum;
vector<int>ans;

vector<int> adj[mxn];

void dfs(int node,int par,int lvl){
    ans[1]+=(lvl*1LL*a[node]);
    sum[node]=a[node];
    for(int child:adj[node]){
        if(child==par)continue;
        dfs(child,node,lvl+1);
        sum[node]+=sum[child];
    }
}

void dfs2(int node,int par){
    for(int child:adj[node]){
        if(child==par)continue;
        //ans[child]= ans[node] - sum[child] +(sum[node]-sum[child]);
        ans[child]= ans[node] - sum[child] +(total-sum[child]);
        dfs2(child,node);
    }
}


signed main() {
    FIO;
	int n;cin>>n;
	a = vector<int>(n+1);
	sum = vector<int>(n+1);
	ans = vector<int>(n+1,0);
    total=0;
	rep(i,1,n) {
		cin >> a[i];
        total+=a[i];
	}

	rep(i,1,n-1){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,-1,0);
	dfs2(1,-1);
    int mx=-1;
	rep(i,1,n){
        //watch2(i,ans[i]);
        mx=max(mx,ans[i]);
    }	
    cout<<mx<<endl;
	return 0;
}