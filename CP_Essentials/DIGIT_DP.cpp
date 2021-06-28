// /// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> num;
// int a, b, d, k;
// int DP[12][12][2];
// /// DP[p][c][f] = Number of valid numbers <= b from this state
// /// p = current position from left side (zero based)
// /// c = number of times we have placed the digit d so far
// /// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

// int call(int pos, int cnt, int f){
//     if(cnt > k) return 0;

//     if(pos == num.size()){
//         if(cnt == k) return 1;
//         return 0;
//     }

//     if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
//     int res = 0;

//     int LMT;

//     if(f == 0){
//         /// Digits we placed so far matches with the prefix of b
//         /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
//         LMT = num[pos];
//     } else {
//         /// The number has already become smaller than b. We can place any digit now.
//         LMT = 9;
//     }

//     /// Try to place all the valid digits such that the number doesn't exceed b
//     for(int dgt = 0; dgt<=LMT; dgt++){
//         int nf = f;
//         int ncnt = cnt;
//         if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
//         if(dgt == d) ncnt++;
//         if(ncnt <= k) res += call(pos+1, ncnt, nf);
//     }

//     return DP[pos][cnt][f] = res;
// }

// int solve(int b){
//     num.clear();
//     while(b>0){
//         num.push_back(b%10);
//         b/=10;
//     }
//     reverse(num.begin(), num.end());
//     /// Stored all the digits of b in num for simplicity
//     memset(DP, -1, sizeof(DP));
//     int res = call(0, 0, 0);
//     return res;
// }

// int main () {
//     cin >> a >> b >> d >> k;
//     int res = solve(b) - solve(a-1);
//     cout << res << endl;
//     return 0;
// }

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
//---------------------------------------------------------------------------------------------------------------//
int dp[100][100][2];
int solve(string&num,int n,int x,bool chk){
    if(x<0)return 0;
    if(n==1){
        if(x>=0 &&x<=9)return 1;
        else return 0;
    }
    if(dp[n][x][chk]!=-1){
        return dp[n][x][chk];
    }
    int ans=0;
    int ub=chk ?(num[(num.length()-n)]-'0'):9; //if chk =1 ub is current digit else up is 9 

    for(int dig=0;dig<=ub;dig++){
        ans+=solve(num,n-1,x-dig,(chk&(dig==ub)));
    }
    return dp[n][x][chk]=ans;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        memset(dp,-1,sizeof(dp));
        string num="15";
        cout<<solve(num,2,5,1);// count of numbers less than num having sum=5
    }
    return 0;   
}