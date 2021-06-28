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
ll solve(ll n){
    ll mx=-1;
    ll mn=11;
    while(n>0){
        ll tmp=n%10;
        mx=max(mx,tmp);
        mn=min(mn,tmp);
        n=n/10;
    }
    return mn*mx;
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll a,k;cin>>a>>k;
        ll ans=a;
        rep(i,2,k){
            if(solve(ans)==0)
                break;
            ans+=solve(ans);
        }
        cout<<ans<<endl;
    }
    return 0;   
}