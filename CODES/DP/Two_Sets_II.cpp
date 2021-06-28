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
int knap(int a[],int n,int sum){
    int dp[n+1][sum+1];
    //cout<<sum<<endl;

    rep(i,0,n){
        rep(j,0,sum){
            if(i==0)dp[i][j]=0;

            else if(j==0)dp[i][j]=1;

            else if(a[i-1]<=j){
                dp[i][j]= (dp[i-1][j] + dp[i-1][j-a[i-1]])%mod;
            }
            else{
                dp[i][j]=(dp[i-1][j])%mod;
            }
        }    
    }
    rep(i,0,n){
        rep(j,0,sum){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;    
    }
    return dp[n][sum];
}    
void solve(){
    int n;cin>>n;
    int a[n];
    int sum = n*(n+1)/2;
    if(sum%2==1){
        cout<<"0"<<endl;
        return;
    }   
    sum=sum/2;
    rep(i,0,n-1)a[i]=i+1;
    int ans= knap(a,n,sum);
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}