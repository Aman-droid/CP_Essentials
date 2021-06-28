#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
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
char get(ll x1,ll y1,ll x2,ll y2){
    if(x1==x2){
        if(y2>y1)return 'U';
        else return 'D';
    }
    else{
        if(x2>x1)return 'R';
        else return 'L';  
    }
    return 'a';
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        ll a[n];
        vpll v(n+2);
        ll mn=1e9,mx=-1e9;
        rep(i,0,n){
            cin>>v[i].ff>>v[i].ss;
            mx=max(mx,v[i].ss);
        }
        mn=v[0].ff;
        char x1,x2;
        ll ans=0;
        rep(i,2,n-1){
            x1=get(v[i-1].ff,v[i-1].ss,v[i].ff,v[i].ss);
            x2=get(v[i].ff,v[i].ss,v[i+1].ff,v[i+1].ss);
            if(x1=='R' && v[i].ss!=mx && (x2=='U' ||x2=='D') ){
                ans++;
            }
            if(x1=='L' && v[i].ss!=mn && (x2=='U' ||x2=='D')){
                ans++;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;   
}