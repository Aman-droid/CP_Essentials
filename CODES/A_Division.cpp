#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define SZ(x) ((ll)x.size())
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

const int32_t M=1e9+7;
const int32_t MM=998244353;
const ll N=0;
  
void solve(){
	ll p,q;cin >> p >> q;
	ll orp = p;
	vector<pll> f;
	ll x = q;
	for(ll i = 2; i * i <= x; i++){
		if(x % i == 0){
			ll cnt = 0;
			while(x % i == 0){
				cnt++;
				x /= i;
			}
			f.pb({i,cnt});
		}
	}
	if(x != 1){
		f.pb({x,1});
	}	
	ll ans = p;
	for(auto x:f){
		ll pr = x.ff;
		ll freq = x.ss;
		ll cnt = 0;
		while(p % pr == 0) 
			p /= pr, cnt++;
		
		ll req = max(cnt - freq + 1, 0LL);
		ll val = 1;
		rep(i,0,req-1) val *= pr;
		ans=min(ans,val);
	}
	cout << orp / ans << "\n";
}
int main(){
	FIO;
	ll T=1;cin>>T;
	while(T--) solve();
	return 0;
}

