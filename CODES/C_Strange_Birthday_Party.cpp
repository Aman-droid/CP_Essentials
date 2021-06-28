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

int main(){
    FIO;
	int T;cin>>T;
	while(T--){
		ll n,m;cin>>n>>m;
		ll k[n];
		ll c[m];
		for(ll i=0;i<n;i++){
			cin>>k[i];
		}
		for(ll i=0;i<m;i++){
			cin>>c[i];
		}
		sort(k,k+n);
		ll cnt=1,ans=0;
		for(ll i=n-1;i>=0;i--){
			if(k[i]<=cnt){
				ans+=c[k[i]-1];
			}
			else if(k[i]>cnt){
				ans+=c[cnt-1];
				cnt++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}