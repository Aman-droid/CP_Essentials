#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;
void solve(){
    int n,m;cin>>n>>m;
    int sum=0,x=0,fl=0;
    int a[n+1];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));     ///dp[i][j] =1  =>  size--> i  j=sum%m is possible.  

    rep(i,0,n-1)cin>>a[i];
    
    if(n>m){
    	cout<<"YES"<<endl;
	}
	else
	{
        dp[1][a[0]%m]=1;

		for(ll i=2;i<=n;i++)
		{
			dp[i][a[i-1]%m]=1;

			for(ll j=0;j<m;j++){
				dp[i][(j+a[i-1])%m] |= (dp[i-1][(j+a[i-1])%m]);
				dp[i][(j+a[i-1])%m] |= (dp[i-1][j]);
			}
		}

		if(dp[n][0]>0) cout<<"YES";
		else cout<<"NO";
    }	
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}