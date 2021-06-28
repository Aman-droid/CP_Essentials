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
while(b>0){
    if(b&1){res=(res*a);b--;}
    a=(a*a);
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//
const int mxn=1e5;
ll calc(ll x){
    ll ans= (x*1LL*(x+1))/2;
    return ans;
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,m,x;cin>>x;
        ll ans=1;
        ll sum=0;
        for(ll i=1;i<32LL;i++){
            sum+=calc(power(2,i)-1LL);
            //ll tmp=(2LL*(power(2,i)-1LL))-i;
            //watch2(sum,x);
            if(sum<=x){
                ans=i;
            }
            else
                break;
        }
        cout<<ans<<endl;
    }
    return 0;   
}