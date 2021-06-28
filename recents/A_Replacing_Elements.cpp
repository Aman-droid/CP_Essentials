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
    int n,d;cin>>n>>d;
    int a[n];
    int fl=0;
    rep(i,0,n-1){
        cin>>a[i];
        if(a[i]>d)fl=1;
    }
    if(fl==0){
        cout<<"YES"<<endl;
        return;
    }

    sort(a,a+n);
    if(a[0]+a[1] <=d){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}