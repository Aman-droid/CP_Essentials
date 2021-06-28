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
    int n,k;cin>>n>>k;
    int a[n];
    rep(i,0,n-1){
        cin>>a[i];
    }
    int i=0;
    int j=n-1;
    while(k>0){
        int tmp = min(a[i],k);
        a[i]=a[i]-tmp;
        a[j]+=tmp;
        k=k-tmp;
        i++;
        if(i==n-1)break;
    }
    rep(i,0,n-1)cout<<a[i]<<" ";
    cout<<endl;
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}