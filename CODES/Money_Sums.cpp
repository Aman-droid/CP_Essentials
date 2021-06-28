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
        int n;cin>>n;
        int sum=n*1000;
        vector<int>a(n);
        for(auto &it:a)cin>>it;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        dp[0][0]=true;
        rep(i,1,n){
            rep(j,0,sum){
                dp[i][j]=dp[i-1][j];
                int left = j-a[i-1];
                if(left>=0 && dp[i-1][left])dp[i][j]=true;
            }
        }
        vector<int>ans;
        rep(j,1,sum){
            if(dp[n][j]){
                ans.pb(j);
            }
        }
        cout<<SZ(ans)<<endl;
        for(auto it:ans)cout<<it<<" ";
        cout<<"\n";
    }
    return 0;   
}