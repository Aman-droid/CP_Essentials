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
int main(){
	FIO;
	int T;cin>>T;
	while(T--){
		ll n;cin>>n;
		ll a[2*n];
		set<ll>s;
		rep(i,0,2*n-1){
			cin>>a[i];
			s.insert(a[i]);
		}
		if(s.size()!=n){
			cout<<"NO"<<endl;
		}
		else{
			set<ll>s2; 
			ll fl=1;
			ll cnt=0;ll prev=0;
			for(auto it=s.rbegin();it!=s.rend();it++){
				ll x=*it;
				x=x-prev;
				if(x<=0){
					fl=0;
					break;
				}
				if(x%(2*(n-cnt))!=0){
					fl=0;
					break;
				}
				else{
					ll y=x/(2*(n-cnt));
					s2.insert(y);
					prev+=2*y;
				}
				cnt++;
			}
			if(s2.size()!=n) fl=0;
			if(s2.size()>0 && *(s2.begin())==0)fl=0;
			
            if(fl)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}		
	}
	return 0;
}