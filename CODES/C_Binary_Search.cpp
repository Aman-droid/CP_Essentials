#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
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
ll inv(ll a)
{
return power(a,mod-2);
}

ll fact[2000007];
ll inr[2000007];
void pre()
{
	fact[0]=1;
	for(ll i=1;i<=2000005;i++)fact[i]=(fact[i-1]*i)%mod;
	inr[0]=1;
	for(ll i=1;i<=2000005;i++)inr[i]=inv(fact[i]);
}

ll ncr(ll n,ll r)
{
	ll a=(fact[n]*inr[r])%mod;
	ll b=(a*inr[n-r])%mod;
	return b;
}
 
void solve(){
	int n,x,pos;
	cin>>n>>x>>pos;
	int cnts = 0, cntb = 0;
	int left = 0, right = n;
	while(left < right){
		int middle = (left + right) / 2;
		if(middle > pos) cntb++;
		if(middle < pos) cnts++;
		if(middle <= pos){
			left = middle + 1;
		}
		else{
			right = middle;
		}
	}
	if(left - 1 == pos);	
		cout << ncr(x-1,cnts) * ncr(n-x,cntb) %mod * fact[(n - cnts - cntb - 1)] % mod * fact[cnts] %mod * fact[cntb] % mod;
}
int main(){
	FIO;
	pre();
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}
