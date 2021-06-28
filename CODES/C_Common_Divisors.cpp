#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
set<ll>s;
void div(ll n){
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);   
        }
    }
}


int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,u,v;cin>>n;
        ll a[n];
        ll ans;
        s.clear();
        rep(i,0,n-1){
            cin>>a[i];
        }
        ans=a[0];
        //watch(ans);
        rep(i,1,n-1){
            ans=gcd(ans,a[i]);
            //watch(i);
            //watch(ans);
        }
        div(ans);
        cout<<SZ(s)<<endl;
    }
    return 0;   
}