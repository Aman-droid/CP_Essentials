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
    int n,x,tmp;cin>>n>>x;
    int a[n+1];
    int fl=0;
    map<int,int>mp;
    rep(i,1,n){
        cin>>a[i];
        if(mp.find(x-a[i])!=mp.end()){
            cout<<mp[x-a[i]]<<" "<<i<<endl;
            fl=1;
        }
        mp[a[i]]=i;
    }
    if(fl==0){
        cout<<"IMPOSSIBLE"<<endl;
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