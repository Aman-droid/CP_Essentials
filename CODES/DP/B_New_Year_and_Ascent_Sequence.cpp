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
int a[mxn];

void solve(){
    int n,N,x;cin>>n;
    int mn,mx,fl,m=0;
    vector<pair<int,int>>pr;
    rep(i,0,n-1){
        cin>>N;
        mn=INF;
        mx=-INF;
        fl=0;
        rep(i,0,N-1){
            cin>>a[i];
            if(a[i]>mn){
                fl=1;
            }
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        if(fl==1){
            m++;
        }
        else{
            pr.push_back({mx,mn});
        }
    }
    sort(pr.begin(),pr.end());
    int ans= m*m + 2*m*(n-m);
    for(int i=0;i<SZ(pr);i++){
        pair<int,int>p={pr[i].second+1,0};
        auto it = pr.end()-lower_bound(all(pr),p);
        ans+=it;
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