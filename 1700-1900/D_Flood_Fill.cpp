#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll           long long
#define endl         '\n'
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define ren(i,a,b)   for(int i=a;i>=b;i--)
#define pll          pair<ll,ll>
#define pii          pair<int,int>
#define vpll         vector<pll>
#define SZ(x)        ((int)x.size())
#define FIO          ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)     cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)  cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb           push_back
#define pf           push_front
#define ff           first
#define ss           second
#define prec(n)      fixed<<setprecision(n)
#define mod          1000000007
#define INF          (ll)(1e18)
#define all(c)       (c).begin(),(c).end()

const ll mxn=2e5;
void solve(){
    int n;cin>>n;
    int col[n+1];

	rep(i,1,n)cin>>col[i];

    int dp[n+1][n+1][2];    
    rep(i,0,n){
        rep(j,0,n){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }

	for(int len=2;len<=n;len++){
		for(int L=1; L+len-1 <=n;L++)
		{
			int R = L+len-1;
            dp[L][R][0] = min(dp[L+1][R][0]+(col[L]!= col[L+1]),dp[L+1][R][1]+(col[L]!=col[R]));
            dp[L][R][1] = min(dp[L][R-1][0]+(col[R]!= col[L]),dp[L][R-1][1]+(col[R]!=col[R-1]));
		}
	}
    int ans=min(dp[1][n][0],dp[1][n][1]);
	cout<<ans<<endl;
}
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}