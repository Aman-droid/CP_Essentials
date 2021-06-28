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
//This time d[i] will be the element at which a subsequence 
//of length i terminates. If there are multiple 
//such sequences, then we take the one that 
//ends in the smallest element.

int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n+1, INF);
    
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
   

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        vector<int>a(n);
        rep(i,0,n-1){cin>>a[i];}
        int ans=lis(a);
        cout<<ans<<endl;
    }
    return 0;   
}