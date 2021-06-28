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

int main() {
    int n, m;cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    int x0;
    cin >> x0;
    if (x0 == 0) {
        rep(i,0,m)dp[0][i]=1;
    } 
    else {
        dp[0][x0] = 1;
    }
    for (int i = 1; i < n; i++) {
        int x;cin >> x;
        if (x==0) {
            for (int j = 1; j <= m; j++) {
	            for (int k : {j-1,j,j+1}) {
	                if (k >= 1 && k <= m) {
	                    (dp[i][j] += dp[i-1][k]) %= mod;
	                }   
	            }
            }
        }
        else {
            for (int k : {x-1,x,x+1}) {
	            if (k >= 1 && k <= m) {
	                (dp[i][x] += dp[i-1][k]) %= mod;
	            }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        (ans += dp[n-1][j]) %= mod;
    }
    cout << ans << endl;
}