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
const int mxN=2e3;
int n, h, l, r, a[mxN], dp[mxN+1][mxN];

void solve(){
    int n,h,l,r;cin>>n>>h>>l>>r;
    int a[n],dp[n+1][h+1];
    
    rep(i,0,n){
        rep(j,0,h){
            dp[i][j]=-INF;
        }
    }

    dp[0][0]=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		for(int j=0; j<h; j++) {
			int nj = (j+a[i]-1)%h;
			dp[i+1][nj] = max(dp[i][j] + (l<=nj && nj<=r) , dp[i+1][nj]);
			
            nj = (j+a[i])%h;
			dp[i+1][nj] = max(dp[i][j] + (l<=nj && nj<=r) , dp[i+1][nj]);
		}
	}

	int ans=0;
	for(int i=0; i<h;i++)
		ans=max(dp[n][i], ans);

	cout << ans<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
