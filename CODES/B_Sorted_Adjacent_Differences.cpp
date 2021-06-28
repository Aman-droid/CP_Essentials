#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
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
signed main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        ll a[n];
        rep(i,0,n-1){cin>>a[i];}
        sort(a,a+n);
        ll i=0,j=n-1;
        vector<ll>res;
        while(i<=j){
            if(i==j){
                res.pb(a[i]);    
            }
            else{
                res.pb(a[j]);
                res.pb(a[i]);
            }
            i++;
            j--;
        }
        reverse(res.begin(),res.end());
        for(auto it:res){
            cout<<it<<" "; 
        }
        cout<<endl;
    }
    return 0;   
}