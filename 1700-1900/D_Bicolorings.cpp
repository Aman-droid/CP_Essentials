#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const int mxn=2e3+5;


void solve(){
    int n,k;cin>>n>>k;
    int dp[n+1][k+1][5];
    rep(i,0,n)rep(j,0,k)rep(l,0,3)dp[i][j][l]=0;
    //dp[i][j][l] => i=len j=comp l=0{0,0} l=1{1,0} l=2{0,1} l=3{1,1} 
	int mod1 = 998244353;
    dp[1][1][0]= 1; 
	dp[1][1][3]= 1;
	dp[1][2][1]= 1;
	dp[1][2][2]= 1;
	
	rep(i,2,n){
		rep(j,1,k){
			dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3])%mod1;
			dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j-1][3])%mod1;
			dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j][2] + dp[i-1][j-1][3])%mod1;
			dp[i][j][3] = (dp[i-1][j][3] + dp[i-1][j][2] + dp[i-1][j][1] + dp[i-1][j-1][0])%mod1;
			
			if(j>2){
				dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-2][2])%mod1;
				dp[i][j][2] = (dp[i][j][2] + dp[i-1][j-2][1])%mod1;
			}
		}
	}
	
    int ans=0;
	rep(i,0,3){
		ans=(ans + dp[n][k][i])%mod1;
	}
	cout<<ans<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}