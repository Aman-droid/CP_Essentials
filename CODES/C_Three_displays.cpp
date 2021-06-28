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
const ll INF=1e15;
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        ll a[n],b[n];
        rep(i,0,n-1){cin>>a[i];}
        rep(i,0,n-1){cin>>b[i];}
        ll ans=INF;
        rep(i,1,n-2){
            int t1=-1;
            ll a1=INF;
            ll a2=INF;
            rep(j,0,i-1){
                if(a[j]<a[i]){
                    a1=min(a1,b[j]);
                }
            }
            rep(k,i+1,n-1){
                if(a[k]>a[i]){
                    a2=min(a2,b[k]);
                }
            }
            if(a1!=INF && a2!=INF){
                ans=min(ans,b[i]+a1+a2);
            }
        }
        if(ans==INF)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;   
}