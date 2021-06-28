#include<bits/stdc++.h>
using namespace std;
const long long mod=10;
int main(){
    long long n;cin>>n;
    long long dp[n+1];
    dp[0]=0;
    dp[1]=1;    
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    long long ans=(dp[n])%mod;
    cout<<ans<<endl;
}