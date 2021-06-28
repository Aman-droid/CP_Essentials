#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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
int t, a, b;
bool solve(int res, int d){
	ll sum = res * 1LL * (res + 1) / 2;
	if(sum < d) 
        return false;
	return 
        (sum-d)%2==0 ;
}	

int main() {		
	cin >> t;
	while(t--){
		cin>>a>>b;
		ll d = abs(a- b);
		if(d == 0){ 
			cout << "0"<<endl;
			continue;
		}
		int res = 1;
		while(!solve(res, d)) res++;
		cout << res << endl;
	}
	return 0;
}
