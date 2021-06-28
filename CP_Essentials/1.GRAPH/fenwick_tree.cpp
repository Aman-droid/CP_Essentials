#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
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
 
struct fenwicktree
{
	ll N;
	vector<ll> tree;
	void init(ll n){
		N = n;
		tree.assign(n + 1, 0); //initial value=0;
	}
	void update(ll idx, ll val)
	{
		while (idx <= N)
		{
			tree[idx] += val;
			idx += idx & -idx;
		}
	}
	
	void updateMax(ll idx, ll val){
		while (idx <= N)
		{
			tree[idx] = max(tree[idx], val);
			idx += idx & -idx;
		}
	}
	ll pref(ll idx)
	{
		ll ans = 0;
		while (idx > 0)
		{
			ans += tree[idx];
			idx =idx - (idx & (-idx)); 
		}
		return ans;
	}
 
	ll rsum(ll l, ll r) //range sum
	{
		return pref(r) - pref(l - 1);
	}
 
	ll prefMax(ll idx)
	{
		ll ans = -2e9;
		while (idx > 0)
		{
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
 
 
 
int32_t main()
{
	FIO;
	ll n, q; cin >> n >> q;
	fenwicktree bit;
	bit.init(n);
 
	for (ll i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		bit.update(x, 1);
	}
 
	while (q--)
	{
		ll k; cin >> k;
 
		if (k >= 1)
		{
			bit.update(k, 1);
		}
 
		else
		{
			k = -k;
 
			ll beg = 1, end = n;
			ll ans;
 
			while (beg <= end)
			{
				ll mid = (beg + end) / 2;
 
				ll cur_pref = bit.pref(mid);
 
				if (cur_pref >= k)
					ans = mid, end = mid - 1;
 
				else
					beg = mid + 1;
			}
 
			bit.update(ans, -1);
		}
	}
 
	ll ans = 0;
 
	for (ll i = 1; i <= n; ++i)
		if (bit.pref(i))
		{
			ans = i;
			break;
		}
 
	cout << ans << '\n';
	return 0;
}

