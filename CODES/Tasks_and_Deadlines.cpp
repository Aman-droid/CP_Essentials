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
    int n,x,y;cin>>n;
    vector<pair<int,int>>v;
    rep(i,0,n-1){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(all(v));
    int ans=0;
    int cur=0;
    rep(i,0,n-1){
        cur+=v[i].first;
        ans+=v[i].second -cur;
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