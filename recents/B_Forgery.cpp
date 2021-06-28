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
int n,m;
int a[1005][1005], b[1005][1005];

void solve(){
    cin >>n>>m;
    for (int i = 1; i <= n; ++i){
        string s;cin >>s;
        s="*"+s;
        for (int j = 1; j <= m; ++j){
            if (s[j] == '#')a[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j] + a[i + 1][j + 2] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2] == 8){
                    b[i][j] = b[i][j + 1] = b[i][j + 2] =1; 
                    b[i + 1][j] = b[i + 1][j + 2] =1;
                    b[i + 2][j] = b[i + 2][j + 1] = b[i + 2][j + 2] = 1;
                }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] != b[i][j]) {
                cout <<"NO"<<endl;
                return;
            }
        }
    }
    cout <<"YES"<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}