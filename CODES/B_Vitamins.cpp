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
const ll INF=1e14;
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll mina=INF,minb=INF,minc=INF,minabc=INF;
        ll minab=INF,minbc=INF,minac=INF;
        ll x,n;cin>>n;
        string s;
        rep(i,0,n-1){
            cin>>x>>s;
            if(s.length()==3)minabc=min(minabc,x);
            else if(s=="AB"||s=="BA")minab=min(minab,x);
            else if(s=="BC"||s=="CB")minbc=min(minbc,x);
            else if(s=="AC"||s=="CA")minac=min(minac,x);
            else if(s=="A")mina=min(mina,x);
            else if(s=="B")minb=min(minb,x);
            else if(s=="C")minc=min(minc,x);
        }
        ll ans=INF;
        ans=min(ans,minabc);
        ans=min(ans,mina+minb+minc);
        ans=min(ans,mina+minbc);
        ans=min(ans,minb+minac);
        ans=min(ans,minc+minab);

        ans=min(ans,minab+minbc);
        ans=min(ans,minab+minac);
        ans=min(ans,minbc+minac);
        if(ans>=INF)cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;   
}