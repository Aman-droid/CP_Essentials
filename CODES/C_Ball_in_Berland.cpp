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
int main()
{
    int T;cin>>T;
    while(T--){
        ll a,b,k,x;
        ll ans=0;
        cin>>a>>b>>k; 
        ll A[a+1]={0},B[b+1]={0};
        for(ll i=0;i<k;i++){ 
            cin>>x; 
            A[x]++;
        }
        for(ll i=0;i<k;i++){ 
            cin>>x; 
            B[x]++;
        }
        ans=k*(k-1LL)/2LL;
        rep(i,1,a){
            ans-=(A[i]*(A[i]-1LL))/2LL;
        }
        rep(i,1,b){
            ans-=(B[i]*(B[i]-1LL))/2LL;
        }
        cout<<ans<<'\n';
    }
    return 0;
}