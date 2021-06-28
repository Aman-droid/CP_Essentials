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
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
//------------------------------------
int main()
{
	int n;cin>>n;
	int ar[n+1];
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		if(ar[i]==1)
		    cnt++;
	}
	if(cnt>0){
		cout<<n-cnt;
	}
	else{
		int ans = mod;
		for(int i=1;i<=n;i++){
			int tmp = ar[i];
			for(int j=i+1;j<=n;j++){
				tmp = gcd(tmp , ar[j]);
				if(tmp==1){
					ans = min(ans , j-i+n-1);
				}
			}
			
		}
		if(ans==mod)cout<<-1;
		else cout<<ans;
	}
}
