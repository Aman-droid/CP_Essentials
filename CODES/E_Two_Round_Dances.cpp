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
const int mxn=100;
ll power(ll x,ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1)res=(res*x)%mod;
        y=y/2;
        x=(x*x)%mod;
    }
    return res;
}

ll inv(ll a)
{
return power(a,mod-2);
}

ll fact[mxn];
ll inr[mxn];
void pre(){
    fact[0]=1;
    for(ll i=1;i<=mxn;i++)fact[i]=(fact[i-1]*i);
    inr[0]=1;
    for(ll i=1;i<=mxn;i++)inr[i]=inv(fact[i]);
}

ll ncr(ll n,ll r)
{
    ll a=(fact[n]*inr[r]);
    ll b=(a*inr[n-r]);
    return b;
}


void solve(){
    int n;cin>>n;
    if(n==2){
        cout<<"1"<<endl;
        return;
    }
    int ans = fact[n];
    int div=fact[n/2]*fact[n/2];
    int N= (n/2)-1;
    ans=ans/div;
    ans=ans/2;
    ans=ans*fact[N]*fact[N];
    cout<<ans<<endl;
}

signed main() {
    FIO;
    pre();
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}