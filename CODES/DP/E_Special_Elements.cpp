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

const int mxn=8005;;
int vis[mxn];

void solve(){
    int n,x;cin>>n;
    vector<int>a(n+1);
    unordered_map<int,int>mp;
    rep(i,1,n)cin>>a[i];
    a[0]=0;
    rep(i,2,n){
        a[i]=a[i]+a[i-1];
        //cout<<pr[i]<<" ";
    }
    //cout<<'\n';    

    rep(i,2,n){
        rep(j,0,i-2){
            if(a[i]-a[j] <= n)
                mp[a[i]-a[j]]++;
        }
    }
    
    int ans=0;

    rep(i,1,n){
        if(mp.count(a[i]-a[i-1])){
            ans++;
        }    
    }
    mp.clear();
    a.clear();
    cout<<ans<<endl;
}

signed main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}