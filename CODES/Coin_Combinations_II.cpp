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

// void solve(ll a[],ll n,ll sum){
//     ll dp[n+1][sum+1];
//     //memset(dp,0,sizeof(dp));
//     for(ll i=0;i<=n;i++){
//         for(ll j=0;j<=sum;j++){
//             if(j==0)dp[i][j]=1;
//             else if(i==0)dp[i][j]=0;
//             else{ 
//                 dp[i][j]=dp[i-1][j]%mod;
//                 if(a[i-1]<=j){
//                     dp[i][j]=(dp[i][j]+dp[i][j-a[i-1]])%mod;
//                 }
//             }
//         }
//     }
//     cout<<dp[n][sum]%mod;
// }
// int main() {
//     //FIO;
//     int T=1;//cin>>T;
//     while (T--){
//         ll n,x;cin>>n>>x;
//         ll a[n];
//         rep(i,0,n-1){cin>>a[i];}
//         solve(a,n,x);
//     }
//     return 0;   
// }

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int &v : arr) cin >> v;

    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1]<=j) {
	            dp[i][j] = (dp[i][j]+dp[i][j-arr[i-1]]) % mod;
            }
        }
    }
    cout << dp[n][sum] << endl;
}