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
    int n;cin>>n;

    char a[n+1][n+1];
    int x1,y1,x2,y2;
    
    int fl=0;
    rep(i,0,n-1){
        rep(j,0,n-1){
            cin>>a[i][j];
            if(fl==0 && a[i][j]=='*'){
                x1=i;
                y1=j;
                fl=1;
            }
            else if(fl==1 && a[i][j]=='*'){
                x2=i;
                y2=j;
                fl=2;
            }
        }
    }
  
    int x3,x4,y3,y4;
    
    if(x1==x2){
        x3=(x1+1)%(n);
        x4=x3;
        a[x3][y1]='*';
        a[x4][y2]='*';
    }

    else if(y1 == y2){
        int N=n+1;
        y3= (y1+1)%n;
        y4=y3;
        a[x1][y3]='*';
        a[x2][y3]='*';
    }

    else{
        a[x1][y2]='*';
        a[x2][y1]='*';
    }
    rep(i,0,n-1){
        rep(j,0,n-1){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
signed main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}