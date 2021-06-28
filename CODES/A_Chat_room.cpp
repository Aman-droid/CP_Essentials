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
int lcs(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    rep(i,0,n){
        rep(j,0,m){
            if(i==0||j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        string s1,s2;
        cin>>s1;
        s2="hello";
        int ans=lcs(s1,s2,SZ(s1),SZ(s2));
        //watch(ans);
        if(ans==SZ(s2)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;   
}