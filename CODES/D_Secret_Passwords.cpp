#include<bits/stdc++.h>
#define ll long long 
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
// vector <int> adj[26]; 
// int vis[26]={0};
// void dfs(int node){
// 	vis[node]=1;
// 	for(auto child:adj[node]){
// 		if(vis[child]==0) 
//             dfs(child);
// 	}
// }
 
// int main()
// {
//     int n,m;cin>>n;
// 	string s;
//     int ans=0;
//     int pr[26]={0};
//     rep(i,0,25){adj[i].clear();vis[i]=0;}
// 	rep(i,0,n-1){
// 		cin>>s;
//         m=s.length();
//         int x=s[0]-'a';
//         pr[x]=1;
//         rep(j,1,m-1){
//             pr[s[j]-'a']=1;
//             if(s[j]==s[0])continue;
//             else{
//                 adj[x].pb(s[j]-'a');
//                 adj[s[j]-'a'].pb(x);
//             }
// 		}
// 	}
// 	rep(i,0,25){
// 		if(pr[i]==1 && vis[i]==0){
// 			dfs(i);
// 			ans++;
// 		}
// 	}
// 	cout<<ans<<endl;
//     return 0;
// }

//creating bipartite graph
const int N = (int)2e5 + 100;
vector<int> adj[N];
char vis[N];

void add(int v, int u) {
	adj[v].pb(u);
	adj[u].pb(v);
}

void dfs(int node) {
	vis[node] = 1;
	for (int to : adj[node]) {
		if (vis[to]==0) {
			dfs(to);
		}
	}
}

int main() {
	int n;cin>>n;
	for (int i = 0; i < n; i++) {
		string s;cin >> s;
		for (char ch : s) {
			add(i, n + ch - 'a'); //means letters of s connected to ith index
		}
	}
	int ans = 0;
	for (int i = n; i < n + 26; i++) {
		if (!adj[i].empty() && vis[i]==0) {
			dfs(i);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}