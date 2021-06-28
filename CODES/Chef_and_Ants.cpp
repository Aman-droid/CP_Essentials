#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
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

int main()
{
	FIO;
	int T;cin>>T;
	while(T--){
		ll n;cin>>n;
		if(n==1){
			int m;cin>>m;
			vector<ll>v1,v2;
			rep(i,0,m-1){
				int x;cin>>x;
				if(x<0){
					v1.pb(0);
				}
				else{
					v2.pb(0);
				}
			}
			if(v1.size()==0 || v2.size()==0){
				cout<<"0"<<endl;
			}
			else{
				ll sum=0;
				v1[0]=min(v1.size(),v2.size());
				v2[0]=v1[0];
				sum+=v1[0];
				for(int i=1;i<v1.size();i++){
					if(v1.size()-i<v1[i-1]){
						v1[i]=v1.size()-i;
					}
					else{
						v1[i]=v1[i-1];
					}
					sum+=v1[i];
				}
				for(int i=1;i<v2.size();i++){
					if(v2.size()-i<v2[i-1]){
						v2[i]=v2.size()-i;
					}
					else{
						v2[i]=v2[i-1];
					}
					sum+=v2[i];
				}
				cout<<sum<<endl;
			}
		}
		else{
			cout<<"0\n";
		}
	}
		
	return 0;
}