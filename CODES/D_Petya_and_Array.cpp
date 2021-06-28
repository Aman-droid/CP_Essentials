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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<ll,ll> ,null_type,less<pair<ll, ll> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//--------------------------------------------------------------------------------------------------------//
const ll INF=1e16;
signed main() {
	FIO;
	int T=1;//cin>>T;
	while (T--){
		ll n,x;cin>>n>>x;
		ordered_set s;   //stores unique elements so store in pairs  
		ll sum=0;
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			ll a;cin>>a;
			sum+=a;
			ll smr=s.order_of_key({sum-x,INF}); //no of elements less than sum-x; 
			ans+=(s.size()-smr);
			s.insert({sum,i});
			if(sum<x)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;   
}