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
    int U,R,D,L,u1,r1,d1,l1;cin>>U>>R>>D>>L;
    int mx=max({U,R,D,L});
    int fl=0;

    rep(i,0,1){
        rep(j,0,1){
            rep(k,0,1){
                rep(l,0,1){
                    u1 = U-i-j;
                    r1 = R-j-k;
                    d1 = D-k-l;
                    l1 = L-l-i;
                    if(u1>=0 && u1<=n-2 && r1>=0 && r1<=n-2 &&d1>=0 && d1<=n-2 &&l1>=0 && l1<=n-2 ){
                        fl=1;
                        cout<<"YES"<<endl;
                        return;
                    }

                }
            }
        }
    }
    cout<<"NO"<<endl;


}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}