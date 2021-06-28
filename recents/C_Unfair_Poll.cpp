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
    int n,m,k,x,y;cin>>n>>m>>k>>x>>y;
    int a[n+1][m+1];

    rep(i,1,n)rep(j,1,m)a[i][j]=0;

    if(n==1){
        int cnt = k/m;
        int rem = k%m;
        rep(i,1,m){
            a[1][i]=cnt;
        }

        for(int i=1;i<=m;i++){
            if(rem>0){
                a[1][i]++;
                rem--;
            }
            else break;
        }
        cout<<a[1][1]<<" "<<a[1][m]<<" "<<a[x][y]<<endl;
    }
    else{
        int rnd = n*m + (n-2)*m;
        
        int cnt = k/rnd; //no of rounds
        int rem = k%rnd;
        rep(i,1,n){
            rep(j,1,m){
                if(i==1 || i==n){
                    a[i][j]=cnt;
                }
                else{
                    a[i][j]=2*cnt;
                }
            }
        }
        rep(i,1,n){
            rep(j,1,m){
                if(rem>0){
                    a[i][j]++;
                    rem--;
                }
                else{
                    break;
                }
            }
        }
        for(int i=n-1;i>=2;i--){
            rep(j,1,m){
                if(rem>0){
                    a[i][j]++;
                    rem--;
                }
                else break;
            }
        }
        int mn=INF,mx=-1;
        rep(i,1,n){
            rep(j,1,m){
                mn=min(a[i][j],mn);
                mx=max(a[i][j],mx);
            }
        }
        cout<<mx<<" "<<mn<<" "<<a[x][y]<<endl;
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