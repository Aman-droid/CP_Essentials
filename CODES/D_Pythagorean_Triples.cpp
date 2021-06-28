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
bool solve(ll x,ll n){
    if(x>n)return false;
    else{
        ll b=((x*x)-1LL)/2LL;
        if(b+1<=n)return true;
        else return false;
    }
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n;cin>>n;
        if(n<5)
            cout<<"0"<<endl;
        else{
            ll x=(ll)sqrt((double)n);
            //watch(x);
            if(x%2==0){
                x--;
            }
            while(1){
                if(solve(x,n)==false){
                    x=x-2;
                    break;
                }
                else{
                    x=x+2;
                }
            }
            ll ans=(x-1)/2;
            cout<<ans<<endl;
        }
    }
    return 0;   
}