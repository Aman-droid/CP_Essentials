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

const int mxn=2e5;

void solve(){
    int n,x;cin>>n;
	vector<int> a;
	vector<ll>vec;

	rep(i,0,n-1) {
        cin>>x;
        a.pb(x);
    }
	sort(all(a));

	auto it=upper_bound(all(a),0)-a.begin();

	if(n==1) cout<<"1"<<endl;
	else if(it==n) cout<<n<<endl;
	else{
		ll mn=INF;
		rep(i,1,it-1){
			mn=min(mn,abs(a[i]-a[i-1]));
		}
		if(a[it]<=mn){
			cout<<it+1<<endl;
		}
		else{
			cout<<it<<endl;
		}
	}
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}