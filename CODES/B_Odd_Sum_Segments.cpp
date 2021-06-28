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
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,k,x;cin>>n>>k;
        ll a[n+1];
        vector<ll>res;
        rep(i,1,n){
            cin>>a[i];
            if(a[i]%2==1){
                res.pb(i);
            }            
        }
        if(SZ(res)<k){
            cout<<"NO"<<endl;
            continue;
        }
        else if((SZ(res)-k)%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        rep(i,0,k-2){
            cout<<res[i]<<" ";
        }
        cout<<n<<endl;
        res.clear();
    }
    return 0;   
}