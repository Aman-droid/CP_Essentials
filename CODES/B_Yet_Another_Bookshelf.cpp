#include<bits/stdc++.h>
#define int long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pint pair<int,int>
#define pii pair<int,int>
#define vpint vector<pint>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (int)(1e18)
#define aint(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5;

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    int cnt=0;
    rep(i,0,n-1){
        cin>>a[i];
        if(a[i]==1){
            cnt++;
        }
    }
    int cur=0,ans=0;
    rep(i,0,n-1){
        if(a[i]==0){
            if(cur==0 || cur==cnt){
                continue;
            }
            else{
                ans++;
            }
        }
        else{
            cur++;
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

