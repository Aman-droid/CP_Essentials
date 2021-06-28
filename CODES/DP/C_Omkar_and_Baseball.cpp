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
    int a[n+1];
    int cnt=0,fl=0;
    int c1=0,c2=0;

    rep(i,1,n){
        cin>>a[i];
        if(a[i]==i){
            cnt++;
            if(fl==0)c1++;
        }
        else{
            fl=1;
        }
    }

    fl=0;
    for(int i=n;i>=1;i--){
        if(a[i]==i){
            if(fl==0)c2++;
        }
        else{
            fl=1;
        }
    }
    if(cnt==n){
        cout<<0<<endl;
    }
    else if(cnt==c1 || cnt==c2 || cnt==c1+c2){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
    }
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
