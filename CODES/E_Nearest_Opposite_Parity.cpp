#include<bits/stdc++.h>
#define ll long long 
#define v2l '\n'
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
const int INF = 1e9;
const int mxn=2e5;
int n;
int a[mxn],ans[mxn];
vector<int>adj[mxn];

void bfs(vector<int> &v1,vector<int> &v2) {
	vector<int> d(n, INF);
	queue<int> q;
	for (auto v : v1) {
		d[v] = 0;
		q.push(v);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto child : adj[cur]) {
			if (d[child] == INF) {
				d[child] = d[cur] + 1;
				q.push(child);
			}
		}
	}
	for (auto v : v2) {
		if (d[v] != INF) {
			ans[v] = d[v];
		}
	}
}
int main() {
	FIO;
	cin >> n;
	rep(i,0,n-1){adj[i].clear();a[i]=0;ans[i]=-1;}
	vector<int> ev, od;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		if (a[i] %2==1) 
			od.pb(i);
		else 
			ev.pb(i);
	}
	for (int i = 0; i < n; ++i) {
		int l = i - a[i];
		int r = i + a[i];
		if (0 <= l) adj[l].pb(i);
		if (r < n) adj[r].pb(i);
	}
	bfs(od, ev);
	bfs(ev, od);
	rep(i,0,n-1)cout << ans[i] << " ";
	cout <<endl;
	
	return 0;
}