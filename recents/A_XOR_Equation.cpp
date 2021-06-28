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
    int sum,xr;cin>>sum>>xr;
    int diff = sum - xr;
    if ((diff & (xr << 1)) || diff & 1) {
        cout << "0"<<endl;
        return ;
    }
    ll ans = 1;

    for(int i = 0; i < 60; ++i) {
        if ((xr >> i) & 1) {
            ans *= 2;
        }
    }
 
    if (sum == xr) {
        ans -= 2; // positive integers
    }

    cout << ans <<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}