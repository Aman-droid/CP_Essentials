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
    int n,m,x,l,r;cin>>n>>m;
    int pr[n+1];
    pr[0]=0;
    rep(i,1,n){
        cin>>x;
        pr[i]=x+pr[i-1];
    }
    while(m--){
        cin>>l>>r;
        cout<<pr[r]-pr[l-1]<<endl;
    }   
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}