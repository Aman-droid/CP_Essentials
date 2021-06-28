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
    int n,c;cin>>n>>c;  //0->stair 1->lift
    int dp[n+1][2];
    int a[n+1],b[n+1];
    rep(i,1,n-1){
        cin>>a[i];
    }
    rep(i,1,n-1){
        cin>>b[i];
    }

    dp[1][0]=0;
    dp[1][1]=0;
    dp[2][0]=a[1];
    dp[2][1]=c+b[1];

    rep(i,3,n){
        dp[i][0] = min(a[i-1]+dp[i-1][0],a[i-1]+ dp[i-1][1]);
        dp[i][1] = min(c+b[i-1]+dp[i-1][0],b[i-1]+ dp[i-1][1]);
    }
    rep(i,1,n){
        cout<<min(dp[i][0],dp[i][1])<<" ";
    }
    cout<<endl;
}   

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}