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
int dp[105][2];

void solve(){
    int n, k, d;cin >> n >> k >> d;
    
    dp[0][0] = 1;  //dp[i][0] ==> sum=i and all edge less than k 
    dp[0][1] = 0;  //
    
    rep(i,1,n)
    {
        dp[i][0] = dp[i][1] = 0;
        
        for(int j = 1 ; j <= k ; ++j)
        {
            if(i-j < 0) break;
            
            if(j < d){

                dp[i][0]=(dp[i][0]+dp[i-j][0])%mod;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;
            }
            else{
                dp[i][1]=(dp[i][1]+dp[i-j][0])%mod;
                dp[i][1]=(dp[i][1]+dp[i-j][1])%mod;
            }
        }
    }

    cout << dp[n][1] <<endl;
}

signed main() {
    FIO;
    int T=1;///cin>>T;
    while (T--){
       solve();
    }
    return 0;   
} 
