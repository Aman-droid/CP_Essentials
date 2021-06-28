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
#define mod1 998244353
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod1;
while(b>0){
    if(b&1){res=(res*a)%mod1;b--;}
    a=(a*a)%mod1;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5;

void solve(){
    int n,m;cin>>n>>m;
    string a,b;
    cin>>a;
    cin>>b;
    
    //watch(a);
    int pr[m+1];
    pr[0]=0;
    
    rep(i,1,m){
        pr[i] = pr[i-1];
        if(b[i-1]=='1')pr[i]++;
    }

    int ans=0;
    int N=m;
    for(int i=n;(i>=1 && N>=1);i--,N--){
        if(a[i-1]=='1'){
            ans=(ans+ pr[N]*(power(2LL,n-i)))%mod1;
        }
    }
    cout<<ans%mod1<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}