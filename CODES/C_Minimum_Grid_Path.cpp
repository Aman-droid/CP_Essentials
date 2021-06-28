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
        ll C[n+1];
        ll N=(n+1)/2;
        vector<ll>A;
        vector<ll>B;
        rep(i,1,n){
            cin>>C[i];
        }

        ll me=C[2];
        ll mo=C[1];
        ll se=0,so=C[1];
        ll ans=1e15,res=1e15;
        ll len=0,rem=0;
        ll rem1=0;
        rep(i,2,n){
            if(i%2==0){
                se+=C[i];
                me=min(me,C[i]);
                len=i/2;
                rem=n-len;
                ans= se + so+ me*rem + mo*rem;
            }
            else{
                so+=C[i];
                mo=min(mo,C[i]);
                len=i/2;
                rem=n-len;
                len++;
                rem1=n-len;
                ans=se+so+me*rem+mo*rem1;
            }
            //watch2(ans,i);
            res=min(res,ans);
            
            
        }
        cout<<res<<endl;
    }
    return 0;   
}