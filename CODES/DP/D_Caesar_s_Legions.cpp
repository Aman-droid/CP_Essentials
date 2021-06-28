#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 100000000
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;

ll dp[105][105][2];

void solve(){
    int  n1,n2,k1,k2;cin>>n1>>n2>>k1>>k2;

	dp[0][0][0]=dp[0][0][1]=1;
	
    for(ll i=0;i<=n1;i++){
		for(ll j=0;j<=n2;j++)
		{
			for(ll k=1;k<=k1 && i-k>=0;k++)
			{
				dp[i][j][0]+=dp[i-k][j][1];
				dp[i][j][0]%=mod1;
			}

			for(ll k=1; k<=k2 && j-k>=0;k++)
			{
				dp[i][j][1]+=dp[i][j-k][0];
				dp[i][j][1]%=mod1;
			}
		}
	}

	ll ans=(dp[n1][n2][0]+dp[n1][n2][1])%mod1;
	cout<<ans;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
