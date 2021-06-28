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
    int w, h;cin >> w >> h;
    int dp[w+1][h+1];
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (i == j) {
	            dp[i][j] = 0;
            } 
            else {
	            dp[i][j] = 1e9;
	            for (int k = 1; k < i; k++) {
	                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
	            }
	            for (int k = 1; k < j; k++) {
	                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
	            }
            }
        }
    }
    cout << dp[w][h] << endl;
}