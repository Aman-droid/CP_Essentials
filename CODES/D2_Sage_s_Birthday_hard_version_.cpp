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
int main()
{
	int  T=1;//cin>>T;
	while(T--)
	{
		ll n;cin>>n;
		vector<int> a(n),b(n);
		rep(i,0,n-1)cin>>a[i];
		sort(a.begin(),a.end());
		int p=0;
		for(int i=1;i<n;i+=2) 
            b[i]=a[p++];
		for(int i=0;i<n;i+=2) 
            b[i]=a[p++];
		int ans=0;
		for(int i=1;i<n-1;i++){
			if(b[i]<b[i-1] && b[i]<b[i+1]) ans++;
		}
		cout<<ans<<endl;
		rep(i,0,n-1) cout<<b[i]<<" ";
        cout<<endl;
	}
	return 0;
}