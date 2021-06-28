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
ll n, m, k, q, l, r, x, y, z;
const ll mxn = 2e5;
ll a[mxn];
ll b[mxn];
ll c[mxn];
string s, t;
ll ans = 0;	
 
void solve() {
	cin >> n;
	rep(i,0,n-1)cin>>a[i];
	a[n] = 0;
	vector<pair<ll, ll>> vec;
	ll pos = 0;
	for (ll i = 0; i <= n; i++) {
		if (a[i] != a[pos]) {
			vec.pb({a[pos], i - pos});
			pos = i;
		}
	}
	ll ans = 0, dom = -1, domv = -1;
	for (ll i = 0; i < vec.size(); i++) {
		if (vec[i].ss == 1) {     //different
			ans++;
			if (vec[i].ff == domv) dom++;
			else dom--;
		} 
		else {
			if (dom > 0 && vec[i].ff == domv) {
				dom = 2;
				++ans;
			} 
			else {
				ans += 2;
				domv = vec[i].ff;
				dom = 2;
			}
		}
	}
	cout << ans <<endl;
}

int main() {
	FIO;
	int T=1;//cin>>T;
	while(T--){
		solve();
	}	
}