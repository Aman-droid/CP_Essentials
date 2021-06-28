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
vector<ll>res;
ll cal(ll x){
    if(x==1){
      res.pb(1);
      return 0;      
    }
    else if(x<=9){
        res.pb(1);
        x--;
        return x;
    }
    else{
        ll tmp=0;
        ll cnt=1;
        ll y=x;
        while(y>0){
            if(y%10>=1){
                tmp+=cnt;
            }
            y=y/10;
            cnt*=10;
        }
        res.pb(tmp);
        return x-tmp; 
    }
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n;cin>>n;
        ll x=n;
        while(x>0){
            x=cal(x);
        }
        cout<<SZ(res)<<endl;
        for(auto it:res)cout<<it<<" ";
        cout<<endl;
    }
    return 0;   
}