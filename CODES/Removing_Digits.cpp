#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
using namespace std;
//--------------------------------------------------------------------------------------------------------//
int main() {
    //FIO;
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        vector<int>dp(n+1,1e8);
        dp[0]=0;
        rep(i,0,n){
            for(char x:to_string(i)){
                dp[i]=min(dp[i],dp[i-(x-'0')]+1);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;   
}