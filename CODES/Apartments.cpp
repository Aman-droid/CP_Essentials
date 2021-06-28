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
int ans=0;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    int a[n],b[m];
    rep(i,0,n-1){
        cin>>a[i];
    }
    rep(i,0,m-1){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0;
    while(i<n  && j<m){
        if(b[j] > a[i]+k ){
            i++;
        }
        else if(b[j] < a[i]-k ){
            j++;
        }
        else{
            i++;
            j++;
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