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
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,m,x;cin>>n;
        int a[n];
        rep(i,0,n-1){cin>>a[i];}
        int dp[n][3];
        dp[0][0]= 1;   //rst
        dp[0][1]= (a[0]==1||a[0]==3)?0:mod;   //cnt
        dp[0][2]= (a[0]==2||a[0]==3)?0:mod;   //gym
        rep(i,1,n-1){
            if(a[i]==0){
                dp[i][0]=1+min(dp[i-1][1],min(dp[i-1][2],dp[i-1][0]));
                dp[i][1]=mod;
                dp[i][2]=mod;
            }
            else if(a[i]==1){
                dp[i][0]=1+min(dp[i-1][1],min(dp[i-1][2],dp[i-1][0]));
                dp[i][1]=min(dp[i-1][2],dp[i-1][0]);
                dp[i][2]=mod;
            }
            else if(a[i]==2){
                dp[i][0]=1+min(dp[i-1][1],min(dp[i-1][2],dp[i-1][0]));
                dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
                dp[i][1]=mod;
            }
            else if(a[i]==3){
                dp[i][0]=1+min(dp[i-1][1],min(dp[i-1][2],dp[i-1][0]));
                dp[i][1]=min(dp[i-1][2],dp[i-1][0]);
                dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
            }           
        }
        int ans=min(dp[n-1][1],dp[n-1][2]);
        ans=min(ans,dp[n-1][0]);
        cout<<ans<<endl;
    }
    return 0;   
}