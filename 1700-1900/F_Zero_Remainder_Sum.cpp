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
#define forn(i, n) for (int i = 0; i < n;i++)
using namespace std;

const int N = 75;

int a[N][N];
int dp[N][N][N][N];

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	rep(i,0, n-1){ 
        rep(j,0,m-1) {
		    cin >> a[i][j];
        }
	}
	
	rep(i,0 ,N-1) 
        rep(j,0, N-1) 
            rep(cnt,0, N-1) 
                rep(rem,0, N-1) 
                    dp[i][j][cnt][rem] = -INF;

	dp[0][0][0][0] = 0;

	rep(i,0, n-1) rep(j,0 ,m-1) rep(cnt,0, m / 2 ) rep(rem,0,k-1) {
		if (dp[i][j][cnt][rem] == -INF) continue;
		
        int ni = (j == m - 1 ? i + 1 : i);  //last row element then i->i+1
		int nj = (j == m - 1 ? 0 : j + 1);
		
        if (i != ni) {  //last element
			dp[ni][nj][0][rem] = max(dp[ni][nj][0][rem], dp[i][j][cnt][rem]);
		} 
        else {
			dp[ni][nj][cnt][rem] = max(dp[ni][nj][cnt][rem], dp[i][j][cnt][rem]);
		}

		if (cnt + 1 <= m / 2) {
			int nrem = (rem + a[i][j]) % k;
			if (i != ni) {  //last element 
				dp[ni][nj][0][nrem] = max(dp[ni][nj][0][nrem], dp[i][j][cnt][rem] + a[i][j]); //updating next row 1st element
			} 
            else {
				dp[ni][nj][cnt + 1][nrem] = max(dp[ni][nj][cnt + 1][nrem], dp[i][j][cnt][rem] + a[i][j]);  //updating next element in the same row
			}
		}
	}
	
	cout << max(0LL, dp[n][0][0][0]) << endl;
	return 0;
}