#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;

signed main() {
    FIO;
    int n;cin>>n;
    int q,l, r;
    vector<int> a(n);
    rep(i,0,n-1)
        cin>>a[i];
 
    vector<vector<pair<int, int>>> dp(20);
    int cur = 1;
    //sparsh table 
    //storing every nth parent in powers of 2 
    for (int i = 0; i<n; i++) dp[0].push_back({a[i], 0});

    for (int deg = 1; deg<20; deg++){
        cur*=2;
        for (int i = 0; i+cur <= n; i++) {
            int left1 = dp[deg-1][i].first;
            int left2 = dp[deg-1][i+cur/2].first;
            int c1 = dp[deg-1][i].second;
            int c2 = dp[deg-1][i+cur/2].second;
            int res_candies = c1 + c2;
            int res_left = (left1 + left2)%10;
            if (left1+left2>=10) res_candies++;
            dp[deg].push_back({res_left, res_candies});
        }
    }
    
    cin>>q;
    while(q--){

        cin>>l>>r;
        int len = (r-l+1);
        int deg = 0;
        while (len%2==0){
            deg++; len/=2;
        }
        cout<<dp[deg][l-1].second<<endl;
    }
}