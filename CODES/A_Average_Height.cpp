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
    int n,x;cin>>n;
    int ans=0;
    vector<int>ev,od;
    rep(i,0,n-1){
        cin>>x;
        if(x%2==1){
            od.push_back(x);
        }
        else{
            ev.push_back(x);
        }
    }
    if(SZ(od)>=SZ(ev)){
        for(auto it:od){
            cout<<it<<" ";
        }
        for(auto it:ev){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        for(auto it:ev){
            cout<<it<<" ";
        }
        for(auto it:od){
            cout<<it<<" ";
        }
        cout<<endl;
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