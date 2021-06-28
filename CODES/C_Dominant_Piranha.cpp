#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5;

void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int mx=-1;
    rep(i,0,n-1){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int ans=-1;
    rep(i,0,n-1){
        if(a[i]==mx){
            if(i-1 >=0 && a[i-1]<a[i]){
                ans=i+1;
                break;
            }
            else if(i+1 <=n-1 && a[i+1]<a[i]){
                ans=i+1;
                break;
            }
            
        }
    }
    if(ans==-1){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
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