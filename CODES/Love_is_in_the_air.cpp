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
ll inv(ll a){
    return power(a,mod-2);
}

int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n;cin>>n;
        ll a[4];
        cin>>a[1]>>a[2]>>a[3];
        if(n==1)cout<<a[1]<<" "<<(a[1])%mod<<endl;
        else if(n==2)cout<<a[2]%mod<<" "<<(a[1]+a[2])%mod<<endl;
        else if(n==3)cout<<a[3]%mod<<" "<<(a[1]+a[2]+a[3])%mod<<endl;
        else {
            ll x=a[2]-a[1];
            ll y=a[3]-a[2];
            ll r=y/x;
            //watch(r);
            ll n1=n-1;
            ll A,B,C;
            A=(power(r,n-1)-1+mod)%mod;
            A=A*inv(r-1);
            A%=mod;
            ll ln = (x*A)%mod;  //add an=ln+a[1];
            ll an=(a[1]+ln)%mod;
            //watch(ln);
            ll b;
            ll y1=(n*(a[1]+ln))%mod;
            //watch(y1);
            b=((n-1)*x*power(r,n-1))%mod;
            //watch(b);
            ll y2=(((b-ln+mod)%mod)*((inv(r-1)+mod)%mod))%mod;
            ll sn=(y1-y2+mod)%mod;
           
            cout<<an<<" "<<sn<<endl;
        }
    }
    return 0;   
}
        
        
        
