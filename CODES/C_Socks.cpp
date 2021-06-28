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

/*//usinf the DFS graph 
const int mxn=5e5;
vector<int>adj[mxn];
int vis[mxn];
int col[mxn];
map<int,int> cnt;
int cc_size;

void dfs(int node){
    vis[node]=1;
    cnt[col[node]]++;
    cc_size++;
    for(int to:adj[node]){
        if(vis[to]==0)
            dfs(to);
    }

}
int main() {
    int T=1;//cin>>T;
    while (T--){
        int n,m,k,u,v;cin>>n>>m>>k;
        rep(i,1,n)cin>>col[i];
        rep(i,1,m){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(vis[i]==0){
                cnt.clear();
                cc_size=0;
                dfs(i);
                int mxm=INT_MIN;
                for(auto it:cnt)
                    mxm=max(mxm,it.ss);
                ///watch(mxm);
                ans+=cc_size -mxm;
            }
        }
        cout<<ans<<endl;

    }
}
*/
//using DSU rank merge
int col[200001];
struct node{
	int par;
	int rank;
	map<int,int> mp;
};
node ar[200001];
 
int find(int a){
	if(ar[a].par == -1) return a;
	
	return 
        ar[a].par = find(ar[a].par);
}

//merge by rank
void merge(int a, int b)
{
	if(a == b)
	return;
	
	if(ar[a].rank < ar[b].rank)
        swap(a , b);
	
	ar[b].par = a;
	ar[a].rank += ar[b].rank;
	
	for(auto it=ar[b].mp.begin(); it != ar[b].mp.end(); it++)
	    ar[a].mp[it->ff] += it->ss;   //storing count of all colours of the nodes which have common node a..
	ar[b].mp.clear();
}
 
int main()
{
	int n,m,k,x,y,res = 0;
	cin>>n>>m>>k;
	rep(i,1,n)
    	cin>>x , ar[i].mp[x]++ , ar[i].par = -1 , ar[i].rank = 1;
	
	rep(i,1,m){
		cin>>x>>y;
		merge(find(x) , find(y));
	}
	
	rep(i,1, n)
	if(ar[i].par == -1)
	{
		int mx = 0;
		for(auto it=ar[i].mp.begin();it!=ar[i].mp.end();it++)
		mx = max(mx , it->ss);
		
		res += ar[i].rank - mx;
	}
	
	cout<<res;
}
