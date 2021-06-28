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
    int n;cin>>n;
    int a[n];
    int ans=0;
    rep(i,0,n-1){
        cin>>a[i];
    }
    if(n==1){cout<<"0"<<endl;return ;}
    sort(a,a+n);
    int tmp=0;
    if(n%2==1){
        tmp=a[n/2];
    }
    else{
        int x=n/2;
        int y=n/2 + 1;
        x--;y--;
        tmp=(a[x]+a[y])/2;
    }
    rep(i,0,n-1){
        ans+=abs(a[i]-tmp);
    }
    cout<<ans<<endl;
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}