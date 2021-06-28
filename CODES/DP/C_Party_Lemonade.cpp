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
    int n,L;cin>>n>>L;
    int c[33];
    int dp[33];

    rep(i,0,32){
        c[i]=INF;
    }
    rep(i,0,n-1){
        cin>>c[i];
    }

    dp[0]=c[0]; //2^0
    //dp[i]  min cost for for atleat i Litres 

    rep(i,1,32){
        dp[i]=min(c[i],2*dp[i-1]);
        //cout<<dp[i]<<" ";
    }
    
    for(int i=30;i>=0;i--){
        if(dp[i]>dp[i+1]){
            dp[i]= dp[i+1];
        }
    }

    // rep(i,0,8){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl; 
    int sum=0;
    int mx=INF;
    rep(i,0,32){
        if((1LL<<i) >=L){
            mx = min(mx,dp[i]);
        }
        if( L&(1LL<<i) ){
            sum+=dp[i];
        }
    }
    sum=min(sum,mx);
    cout<<sum<<endl;  
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}