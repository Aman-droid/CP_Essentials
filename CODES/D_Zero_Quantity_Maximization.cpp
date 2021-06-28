#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pii pair<ll,ll>
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

const ll mxn = 3e5;
map<pii, ll> mp;
ll a[mxn],b[mxn];
ll n;

void upt(pii & a)
{
    if(a.ff<0){
        a.ff *=-1;
        a.ss *=-1;
    }
    else if(a.ff==0 && a.ss<0)
        a.ss*=-1;
    ll tmp= gcd(abs(a.ff),abs(a.ss));
    a.ff/=tmp;
    a.ss/=tmp;
}


int main()
{
    FIO;
	cin>>n;
	rep(i,0,n-1)cin>>a[i];
	rep(i,0,n-1)cin>>b[i];
	ll ans = 0;
	ll cnt = 0;
    rep(i,0,n-1){
		if(a[i] == 0){
			if(b[i] == 0)
				cnt++;
		}
		else{
			pii p ={-b[i], a[i]};
			upt(p);
			mp[p]++;
			ans = max(ans, mp[p]);
		}
	}
	cout <<cnt+ans << endl;
}

