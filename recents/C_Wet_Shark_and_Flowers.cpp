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
//expectation =summation of pi*mi
const int mxn=2e5;

void solve(){
    int n,p;cin>>n>>p;
    int l[n],r[n];

    rep(i,0,n-1){
        cin>>l[i]>>r[i];
    }
    int j;
    long double pi,pj,li,lj;
    long double exp=0;
    long double prob;
    rep(i,0,n-1){
        j  = (i+1)%n;
        li = (r[i]-l[i]+1);
        lj = (r[j]-l[j]+1);
        pi = (r[i]/p) - ((l[i]-1)/p);
        pj = (r[j]/p) - ((l[j]-1)/p);
        prob = 1LL -(((li-pi)/li)*((lj-pj)/lj));
        exp+=prob;
    }
    exp=exp*2000.00;
    cout<<fixed<<setprecision(12)<<exp<<endl;
}


signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}