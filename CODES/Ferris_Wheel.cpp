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
    int n,x;cin>>n>>x;
    int a[n];
    int ans=0;
    rep(i,0,n-1){
        cin>>a[i];
    }
    sort(a,a+n);
    deque<int >dq;
    rep(i,0,n-1){
        dq.push_back(a[i]);
    }
    while(!dq.empty()){
        if(SZ(dq)==1){
            ans++;
            dq.pop_back();
        }
        else if(dq.back() + dq.front() >x){
            dq.pop_back();
            ans++;
        }
        else{
            dq.pop_back();
            dq.pop_front();
            ans++;
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