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
    int n,x;cin>>n;
    set<int>s;
    int a[n+1];
    rep(i,1,n){
        cin>>a[i];
        s.insert(a[i]);
    }
    if(SZ(s)==1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        int x,y;
        x=1;
        rep(i,2,n){
            if(a[i]!= a[1]){
                y=i;
                break;
            }
        }
        rep(i,2,n){
            if(a[i]==a[1]){
                cout<<y<<" "<<i<<endl;
            }
            else{
                cout<<"1"<<" "<<i<<endl;
            }
        }

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