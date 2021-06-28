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
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        vector<ll>A,B,C;
        rep(i,a,b){
            A.pb(i);
        }
        rep(i,b,c){
            B.pb(i);
        }
        rep(i,c,d){
            C.pb(i);
        }
        ll ans=0;
        ll n=SZ(C);
        ll t=min(SZ(A),SZ(B));
        ll mn=A[0]+B[0];
        ll mx=A[SZ(A)-1]+B[SZ(B)-1];
        rep(tmp,mn,mx){
                ll p = min(tmp-mn,mx-tmp)+1LL;
                p = min(p,t);
                ll it=lower_bound(C.begin(),C.end(),tmp)-C.begin();
                //watch(it);
                if(it>=n){
                    ans+=(p*n);
                }
                else 
                    ans+=(p*it);
        }
        cout<<ans<<endl;
    }
    return 0;   
}