#include<bits/stdc++.h>
#define ll long long 
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
//--------------------------------------------------------------------------------------------------------//
const int mxn=2e5;

signed main()
{
    FIO;
    ll n, k;cin>>n>>k;
    ll a[n];

    rep(i,0,n-1)cin>>a[i];

    vector<int> cnt(10005, 0);
    
    rep(i,0,n-1){
        cnt[a[i]]++;
    }

    ll ans = 0;
    if (k == 0){
        for(auto it : cnt)
            ans += it * 1LL * (it - 1) / 2;
    }
    else{
        
        for(int i = 0; i < 10003; i++){
            for(int j = 0; j < i; j++){
                if (__builtin_popcount(i ^ j) == k)
                    ans += cnt[i] * 1ll * cnt[j];
            }
        }
    }
    cout << ans << endl;
}