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
const ll INF=1e12;
int main(){
	FIO;
	int T;cin>>T;
	while(T--){
		ll a,b;cin>>a>>b;
		if(b>a){
			cout<<"1"<<endl;
			continue;
		}
		ll y=sqrt(a);
		ll ans=INF;
		ll x=0;
		if(b==1){
			b++;x=1;
		}
		rep(i,b,max(b,y)){
			ll cnt=x+1;
			ll k=a;
			while((k/i)!=0){
				k=k/i;
				cnt++;
			}
			ans=min(ans,cnt);
			x++;
		}
		cout<<ans<<endl;
	}
	return 0;
}