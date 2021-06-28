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
bool comp(pll &a, pll b){
    if(a.ff*b.ss != b.ff*a.ss){
        return a.ff*b.ss > b.ff*a.ss;
    }
    else{
        return b.ss >= a.ss;
    }
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,k;cin>>n>>k;
        vector<pll>v;
        ll a[n],b[n];
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,n-1)cin>>b[i];
        rep(i,0,n-1){
            v.pb({a[i],b[i]});
        }
        sort(v.begin(),v.end(),comp);
        ll req=k;
        ll cur=0;
        ll ans=0;
        rep(i,0,n-1){
            if(a[i]<req){
                ans+=b[i];
                req=req-a[i];
            }
            else if(a[i]==req){
                req=req-a[i];
                ans+=b[i];
            }
            else {
                int j=i;
                
            }
        }
    }
    return 0;   
}