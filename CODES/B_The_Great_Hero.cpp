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
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll A,B,n,m,x;cin>>A>>B>>n;
        ll a[n],b[n];
        rep(i,0,n-1){cin>>a[i];}
        rep(i,0,n-1){cin>>b[i];}
        vector<pll>v;
        rep(i,0,n-1){
            v.pb({a[i],b[i]});
        }
        sort(v.begin(),v.end());
        ll sum=0;
        ll tmp;
        rep(i,0,n-2){
            tmp=(v[i].ss+A-1LL)/A;
            tmp=tmp*v[i].ff;
            B=B-tmp;
        }
        if(B<=0){
            cout<<"NO"<<endl;
        }
        else{
            tmp=(v[n-1].ss+A-1LL)/A;
            tmp--;
            tmp=tmp*v[n-1].ff;
            B=B-tmp;
            if(B>=1){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;   
        }
    }
    return 0;   
}