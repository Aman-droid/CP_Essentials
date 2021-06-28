#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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

int mincoin(int coins[], int n, int sum) 
{ 
    int dp[sum+1]; 
    dp[0] = 0; 
    
    for (int i=1; i<=sum; i++) 
        dp[i] = INT_MAX; 
  
    for (int i=1; i<=sum; i++) { 
        for (int j=0; j<n; j++) 
            if (coins[j] <= i) { 
                int sub_res = dp[i-coins[j]]; 
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) 
                    dp[i] = sub_res + 1; 
          } 
    } 
    if(dp[sum]==INT_MAX)
        return -1;
    else 
        return dp[sum]; 
} 
  
int main() 
{ 
    FIO;
    int n,x;cin>>n>>x;
    int coins[n];
    rep(i,0,n-1)cin>>coins[i]; 
    int ans=mincoin(coins,n,x);
    cout<<ans<<endl;
    return 0; 
}