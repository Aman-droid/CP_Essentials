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
	int t;cin>>t;
//	t=1;
	while(t--){
		ll n,x;cin>>n>>x;
		ll A[n],B[n];
		ll sum=0,sum2=0;
		ll cnt=0;
		for(ll i=0;i<n;i++){
			cin>>A[i];
			B[i]=A[i]%x;
			sum+=(A[i]/x);
			if(B[i]){
				cnt++;
			}
			sum2+=B[i];
		}
		if(sum2%x){
			cout<<sum+(sum2/x)+1<<" ";
		}
		else{
			cout<<sum+(sum2/x)<<" ";
		}
		cout<<sum+cnt<<"\n";
	}
	return 0;
}