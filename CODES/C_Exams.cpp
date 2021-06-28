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
bool comp(pll & a,pll &b){
    if(a.ff!=b.ff)
      return a.ff<b.ff;
    else
        return a.ss<b.ss; 
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x,y;cin>>n;
        vpll v;
        ll ans1=-1,ans2=-1,ans=INT_MAX;
        rep(i,0,n-1){
            cin>>x>>y;
            v.pb({x,y});
        }
        sort(v.begin(),v.end(),comp);
        ans=min(v[0].ff,v[0].ss);
        for(auto it:v){
            ans1= (it.ff>=ans)? it.ff:mod;
            ans2= (it.ss>=ans)? it.ss:mod;
            ans=min(ans1,ans2);
        }
        cout<<ans<<endl;
    }
    return 0;   
}