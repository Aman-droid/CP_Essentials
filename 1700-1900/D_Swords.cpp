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
    int n,x,y,z;cin>>n;
    int a[n];

    set<int>s;
    int mx=-1,mn=INF,gc=0;
    int sum=0;

    rep(i,0,n-1){
        cin>>a[i];
        gc=gcd(gc,a[i]);
        s.insert(a[i]);
        mx=max(a[i],mx);
        mn=min(a[i],mn);
        sum+=a[i];
    }
    gc=mx-a[0];
    rep(i,0,n-1){
        gc=gcd(mx-a[i],gc); 
    }
     
    y = ((n*mx)-sum)/gc;
    cout<<y<<" "<<gc<<endl;
    
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}