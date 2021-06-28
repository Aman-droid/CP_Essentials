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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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

//-------------------soln-----------------------------// 
const ll mxn = 2e5 + 5;

ll n, mx = -1;
ll pos = 1;
ll a[mxn], ans[mxn];
 
void solve(){
    cin >> n;
	rep(i,1,n)cin >> a[i];
    ll cur,val;
	rep(i,1,n){
		cur = a[i];
        val = a[i];
		for(ll j = i - 1; j >= 1; j--){
			cur = min(cur, a[j]);
			val += cur;
		}
		cur = a[i];

		for(ll j = i + 1; j <= n; j++){
			cur = min(cur, a[j]);
			val += cur;
		}

		if(val > mx){
			mx = val;
			pos = i;
		}
	}
	ans[pos] = a[pos];
	cur = a[pos];

	for(ll i = pos - 1; i >= 1; i--)
	{
		cur = min(cur, a[i]);
		ans[i] = cur;
	}
	cur = a[pos];
	for(ll i = pos + 1; i <= n; i++)
	{
		cur = min(cur, a[i]);
		ans[i] = cur;
	}		
	for(ll i = 1; i <= n; i++)
		cout << ans[i] << " ";
}

signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    ll T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}

