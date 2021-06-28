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
        ll n,k,x;cin>>n>>k;
        ll ans=0;
        if(k>=n){
            ans=k/n;
            if((k%n)!=0)ans++;
            cout<<ans<<endl;
        }
        else{
            if(k==1){
                cout<<"1"<<endl;
            }
            else if(n%k==0)
            {
                cout<<"1"<<endl;
            }
            else{
                ll tmp=n%k;
                k=n+(k-tmp);
                ans=k/n;
                //watch(k);
                if((k%n)!=0)ans++;
                cout<<ans<<endl;
            }
        }
    }
    return 0;   
}