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
while(b>0){
    if(b&1){res=(res*a);b--;}
    a=(a*a);
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(){
    int n,m;cin>>n>>m;
    int x,k,tmp=0;
    int a[2*n+1][m],b[2*n+1][m];;
    rep(i,0,2*n)rep(j,0,m-1)a[i][j]=0,b[i][j]=0;
    int fl=0,fl1=0;
    int ans=-1;
    
    cin>>k;
    rep(i,1,k){
        cin>>x;
        x--;
        a[0][x]=1;
        b[0][x]=1;
    }

    rep(i,1,n){
        cin>>k;
        tmp=0;
        rep(j,1,k){
            cin>>x;
            x--;
            a[i][x]=1;
        }
    }

    int t;

    rep(i,1,2*n){
        fl1=0;
        t = (i>n) ? i-n : i;

        rep(j,0,m-1){
            b[i][j]=b[i-1][j]^a[t][j];
        }
        rep(p,0,m-1){
            if(b[i][p]==1){
                fl1=1;
                break;
            }
        }
        if(fl1==0){
            cout<<i<<endl;
            return;
            ans=i;
            fl=1;
            break;
        }
    }
    cout<<-1<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}