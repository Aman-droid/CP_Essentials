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
const int mxn=3e5;
ll dp[3][mxn] , n , cnt[3];

int main()
{
    FIO;
	ll l,r;cin>>n>>l>>r;
	l+=2 , r+=3;
	for(int i=0;i<3;i++)
	 cnt[i] =(r-i)/3 - (l-i)/3; 
	
	dp[0][0] = 1;
	rep(i,1,n)
	{
		dp[0][i] = ((dp[0][i-1]*cnt[0])%mod + (dp[1][i-1]*cnt[2])%mod + (dp[2][i-1]*cnt[1])%mod) % mod;
		dp[1][i] = ((dp[0][i-1]*cnt[1])%mod + (dp[1][i-1]*cnt[0])%mod + (dp[2][i-1]*cnt[2])%mod) % mod;
		dp[2][i] = ((dp[0][i-1]*cnt[2])%mod + (dp[1][i-1]*cnt[1])%mod + (dp[2][i-1]*cnt[0])%mod) % mod;
	}
	cout<<dp[0][n];
}