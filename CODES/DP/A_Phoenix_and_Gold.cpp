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
    int n,x;cin>>n>>x;
    vector<int>a(n);
    vector<int>vis(n,0);
    
    rep(i,0,n-1){
        cin>>a[i];
    }
    sort(all(a));
    reverse(all(a));
    int N=n;
    int fl=0;
    int sum=0;
    vector<int>ans;
    rep(j,0,n-1){
        fl=0;
        rep(i,0,n-1){
            if(sum+a[i]!=x && vis[i]==0){
                vis[i]=1;
                sum+=a[i];
                //cout<<a[i]<<endl;
                ans.push_back(a[i]);
                fl=1;
                break;
            }
        }
        //cout<<"fl  ---->"<<fl<<endl;
        if(fl==0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    for(auto it:ans){
        cout<<it<<" "; 
    }
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