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
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(){
    int n,m,mn;cin>>n>>m;
    int a[n+2][m+2];
    vector<pair<string,int>>res;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    if(m >= n){
        rep(i,1,n){
            mn= 1e3;
            rep(j,1,m)mn=min(mn,a[i][j]);
            rep(j,1,m)a[i][j]-= mn;
            rep(j,1,mn){
                res.pb({"row",i});
            }

        }
        rep(j,1,m){
            mn= 1e3;
            rep(i,1,n)mn=min(mn,a[i][j]);
            rep(i,1,n)a[i][j]-= mn;
            rep(i,1,mn){
                res.pb({"col",j});
            }

        }
    }
    else{
        rep(j,1,m){
            mn= 1e3;
            rep(i,1,n)mn=min(mn,a[i][j]);
            rep(i,1,n)a[i][j]-= mn;
            rep(i,1,mn){
                res.pb({"col",j});
            }
        }
        rep(i,1,n){
            mn= 1e3;
            rep(j,1,m)mn=min(mn,a[i][j]);
            rep(j,1,m)a[i][j]-= mn;
            rep(j,1,mn){
                res.pb({"row",i});
            }
        }
    }
    int fl=0;
    rep(i,1,n){
        rep(j,1,m){
            if(a[i][j]!=0){
                fl=1;
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<SZ(res)<<endl;
    for(auto it:res){
        cout<<it.ff<<" "<<it.ss<<endl;
    } 
 
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
