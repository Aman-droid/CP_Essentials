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
    int n;
    string s;cin>>s;
    n=SZ(s);
    int dp[n+1];
    for(int i=0;i<n;i++){
        if(s[i]=='w' || s[i]=='m'){
            cout<<"0"<<endl;
            return;
        }
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if( s[i-1] == s[i-2]  && (s[i-1]=='u' || s[i-1]=='n')){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        else{
            dp[i] = (dp[i-1])%mod;
        }
    }
    cout<<dp[n]<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}