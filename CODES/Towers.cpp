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
    int n,x,val;cin>>n;
    int a[n];
    multiset<int>s;
    rep(i,0,n-1){
        cin>>a[i];
    }
    int ans=0;
    rep(i,0,n-1){
        x=a[i];
        auto it=s.upper_bound(x);
        if(it==s.end()){
            ans++;
            s.insert(x);
        }
        else{   
            val=x;
            s.erase(it);
            s.insert(x);
        }
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