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
map<int,int>mp, mmp;
int a[100];
int main()
{
	int T;cin>>T;
	while(T--){
		int n, ans = 0;
		cin>>n;
		for(int i = 1; i <= n; ++i){
			cin>>a[i];
			mmp[a[i]] = 1;
		}
		rep(i,1,n){
			if(mp[a[i]] == 0){
				mp[a[i]] = 1;
			}
			else{
				int t = (a[i] / 10) * 10;
				for(int j = t; j < t + 10; j++){
					if(mp[j]==0 && mmp[j] == 0){
						mp[j] = 1;
						a[i] = j;
						ans++;
						break;
					}
				}
			}
		}
		mp.clear();
		mmp.clear();
		cout<<ans<<endl;
		for(int i = 1;i <= n; ++i)
		printf("%04d\n", a[i]);
	}
}