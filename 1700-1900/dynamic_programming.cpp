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

void dp1(){
    int n,sum;cin>>n>>sum;
    int coin[n],dp[sum+1]={0};
    rep(i,0,n-1)cin>>coin[i];
    dp[0]=1;
    rep(i,1,sum){
        rep(j,0,n-1){
            if(coin[j]<=i){
                dp[i]=(dp[i]+dp[i-coin[j]])%mod;
            }
        }
    }
    cout<<dp[sum]<<endl;
}

void dp2(){
    int n,W;cin>>n>>W;
    int a[n],wt[n];
    int dp[n+1][W+1];  //state dp[i][j] ans when size-> 0 to i-1 & mx weight=j
    rep(i,0,n){
        rep(j,0,W){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],a[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W]<<endl;
}
    



void solve(){

}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        cout<<"T"<<endl;
       solve();
    }
    return 0;   
}