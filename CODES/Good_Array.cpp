#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
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

const ll mxn=1e6;
ll phi[mxn];
void euler() 
{  
    for (ll i=1; i<=mxn; i++) 
        phi[i] = i; 
    for (ll p=2; p<=mxn; p++) { 
        if (phi[p] == p){ 
            phi[p] = p-1; 
            for (int i = 2*p; i<=mxn; i += p){ 
                phi[i] = (phi[i]/p) * (p-1); 
            } 
        } 
    } 
 
    // Print precomputed phi values 
    for (int i=1; i<=mxn; i++) 
    cout << "Totient of " << i << " is "
        << phi[i] << endl; 
} 

// dp[i][j] is going to store true if sum j is 
// possible with array elements from 0 to i. 
bool** dp; 
  
void display(const vector<int>& v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
} 
  
// A recursive function to print all subsets with the 
// help of dp[][]. Vector p[] stores current subset. 
void printSubsetsRec(int arr[], int i, int sum, vector<int>& p) 
{ 
    // If we reached end and sum is non-zero. We print 
    // p[] only if arr[0] is equal to sun OR dp[0][sum] 
    // is true. 
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        p.push_back(arr[i]); 
        display(p); 
        return; 
    } 
  
    // If sum becomes 0 
    if (i == 0 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    // If given sum can be achieved after ignoring 
    // current element. 
    if (dp[i-1][sum]) 
    { 
        // Create a new vector to store path 
        vector<int> b = p; 
        printSubsetsRec(arr, i-1, sum, b); 
    } 
  
    // If given sum can be achieved after considering 
    // current element. 
    if (sum >= arr[i] && dp[i-1][sum-arr[i]]) 
    { 
        p.push_back(arr[i]); 
        printSubsetsRec(arr, i-1, sum-arr[i], p); 
    } 
} 
  
// Prints all subsets of arr[0..n-1] with sum 0. 
void printAllSubsets(int arr[], int n, int sum) 
{ 
    if (n == 0 || sum < 0) 
       return; 
  
    // Sum 0 can always be achieved with 0 elements 
    dp = new bool*[n]; 
    for (int i=0; i<n; ++i) 
    { 
        dp[i] = new bool[sum + 1]; 
        dp[i][0] = true; 
    } 
  
    // Sum arr[0] can be achieved with single element 
    if (arr[0] <= sum) 
       dp[0][arr[0]] = true; 
  
    // Fill rest of the entries in dp[][] 
    for (int i = 1; i < n; ++i) 
        for (int j = 0; j < sum + 1; ++j) 
            dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || 
                                       dp[i-1][j-arr[i]] 
                                     : dp[i - 1][j]; 
    if (dp[n-1][sum] == false) 
    { 
        printf("There are no subsets with sum %d\n", sum); 
        return; 
    } 
  
    // Now recursively traverse dp[][] to find all 
    // paths from dp[n-1][sum] 
    vector<int> p; 
    printSubsetsRec(arr, n-1, sum, p); 
} 
  
// Driver code 
int main() 
{ 
     arr[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 10; 
    printAllSubsets(arr, n, sum); 
    return 0; 
} 