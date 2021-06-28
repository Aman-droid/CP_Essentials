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
    int n,L,m;cin>>n>>L>>m;
    int a[n+1],l[n+1];
    int x=0;
    int ans=0;
    rep(i,1,n){
        cin>>a[i]>>l[i];
    }
    if(n==0){
        ans+=L/m;
        cout<<ans<<endl;
        return;    
    }
    rep(i,1,n){
        if(a[i]- x >=m )ans+=(a[i]-x)/m;
        x=a[i]+l[i];
    }
    ans+=(L-(a[n]+l[n]))/m;
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