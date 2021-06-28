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

bool comp(pair<int,int>& a ,pair<int,int>& b){
    if(a.first !=b.first){
        return a.first>b.first;
    }
    else{
        return a.second<b.second;
    }
}
void solve(){
    int n,k,tmp=0,f;cin>>n>>k;
    int a[n];
    rep(i,0,n-1)cin>>a[i];
    vector<pair<int,int>>res;
    rep(i,0,30){
        tmp=0;
        f = 1LL<<i;
        rep(j,0,n-1){
            if(a[j]&f){
                tmp++;
            }
        }
        tmp=tmp*f;
        res.push_back({tmp,i});
    }
    
    sort(res.begin(),res.end(),comp);
    int ans=0;
    rep(i,0,k-1){
        ans+=1LL << res[i].second;
    }
    cout<<ans<<endl;

}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}