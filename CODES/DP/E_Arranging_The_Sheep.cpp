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
    vector<int>pr(n+2,0),sf(n+2,0);
    string s;cin>>s;
    if(s[0]=='*'){
        pr[1]=1;
    }
    if(s[n-1]=='*'){
        sf[n]=1;
    }
    rep(i,1,n){
        if(s[i-1]=='*'){
            pr[i]=1+pr[i-1];
        }
        else{
            pr[i]=pr[i-1];
        }
    }
    for(int i=n-1;i>=1;i--){
        if(s[i-1]=='*'){
            sf[i]=1+sf[i+1];
        }
        else{
            sf[i]=sf[i+1];
        }
    }
    int ans=0;
    rep(i,1,n){
        if(s[i-1]=='.'){
            ans+=min(pr[i],sf[i]);
        }
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