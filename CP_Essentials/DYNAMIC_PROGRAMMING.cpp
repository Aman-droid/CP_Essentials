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
 
int t[1005][10005];
// 0-1 Knapsack problem RECURSION
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Base Case 
    if (n == 0 || W == 0) 
        return 0; 

    if (wt[n - 1] > W) 
        return knapSack(W, wt, val, n - 1); 
  
    // Return the maximum of two cases: 
    // (1) nth item included 
    // (2) not included 
    else
        return max( val[n - 1] + knapSack(W - wt[n - 1],  wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
} 
//memo
int knapSack2(int W, int wt[], int val[], int n) 
{ 
    // Base Case 
    if (n == 0 || W == 0) 
        return 0; 

    if (wt[n - 1] > W){ 
        t[n][W]=knapSack(W, wt, val, n - 1);
        return t[n][W];
    } 
    if(t[n][W]!=-1)
        return t[n][W];
    // Return the maximum of two cases: 
    // (1) nth item included 
    // (2) not included 
    else{
        t[n][W]= max( val[n - 1] + knapSack(W - wt[n - 1],  wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
        return t[n][W];
    } 
}

int knapSack3(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    //i->size  j->weight of bag
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1]+ K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
    return K[n][W]; 
}

/*
int main() {
    int n, x;cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int&v : price) cin >> v;
    for (int&v : pages) cin >> v;
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-price[i-1];
            if (left >= 0) {
	            dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
}
*/
  
int main() { 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 };
    memset(t,-1,sizeof(t)); 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 