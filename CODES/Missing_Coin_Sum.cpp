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
    int n ;cin>>n;
    int a[n];
    rep(i,0,n-1){
        cin>>a[i];
    }
    sort(a,a+n);
    int p=0,mn=1;
    rep(i,0,n-1){
        if(p + mn<a[i]){
            cout<<p+mn<<endl;
            return;
        }
        mn+=p;
        p=a[i];
    }
    cout<<p+mn<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}