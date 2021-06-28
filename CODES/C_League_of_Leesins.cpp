#include<bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007	
#define vll vector<ll>
#define inf 1e18
#define pll pair<ll,ll>
#define PI acos(-1)
#define endl '\n'
using namespace std;

const ll mxn=2e5;
ll n,t;
vector<ll> adj[mxn];
ll vis[mxn],cnt[mxn];
int main() 
{
	cin>>n;ll x,y,z;
	for(ll i=1; i<=n-2; i++){
		cin>>x>>y>>z;
		adj[x].pb(y),adj[x].pb(z);
		adj[y].pb(x),adj[y].pb(z);
		adj[z].pb(x),adj[z].pb(y);
		cnt[x]++,cnt[y]++,cnt[z]++;
	}
	for(ll i=1; i<=n; i++) {
		if(cnt[i]==1){
			x=i;
			break;
		}
	}
	if(cnt[adj[x][0]]==2) y=adj[x][0];
	else y=adj[x][1];
	vis[x]=vis[y]=1;
	cout<<x<<" "<<y<<" ";
	for(ll i=1; i<=n-2; i++){
		ll z;
        for(int it:adj[x]){
            if(vis[it]==0){
                z=it;    
            }
        }
		vis[z]=1;
		cout<<z<<" ";
		x=y; y=z;
	}
	cout<<endl;
}