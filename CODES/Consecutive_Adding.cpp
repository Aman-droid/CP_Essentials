#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
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

void solve(){
    ll m,n,X;cin>>m>>n>>X;

    ll A[m+1][n+1],B[m+1][n+1];
    rep(i,1,m){
        rep(j,1,n){
            cin>>A[i][j];
        }
    }
    rep(i,1,m){
        rep(j,1,n){
            cin>>B[i][j];
            A[i][j]=A[i][j]-B[i][j];
        }
    }

    ll x1=n-X+1;
    ll tmp;
    rep(i,1,m){
        rep(j,1,x1){
            tmp=A[i][j];
            if(A[i][j]==0){
                continue;
            }
            else{
                rep(k,j,j+X-1){
                    A[i][k]-=tmp;
                }
            }
        }
    }
    // rep(i,1,m){
    //     rep(j,1,n){
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    
    ll x2=m-X+1;
    ll fl=0;
    rep(i,x1+1,n){                 //column
        rep(j,1,x2){              //row
            tmp=A[j][i];
            if(A[j][i]==0){
                continue;
            }
            else{
                rep(k,j,j+X-1){
                    A[k][i]-=tmp;
                }
            }
        }
    }

    rep(i,x2+1,m){
        rep(j,x1+1,n){
            if(A[i][j]!=0){
                fl=1;
                break;
            }
        }
    }

    if(fl==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return;
}

signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}