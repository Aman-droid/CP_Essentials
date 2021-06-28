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
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        ll x,y,x1,x2,y1,y2;cin>>x>>y>>x1>>y1>>x2>>y2;
        ll tx=b-a;
        tx=tx+x;
        ll ty=d-c;
        ty=ty+y;
        int fl=0;
        if(x1==x2 && ( abs(a)>0) )
            cout<<"No"<<endl;
        else if(y1==y2 && ( abs(c)>0) )
            cout<<"No"<<endl;
        else if(tx>=x1 && tx<=x2 && ty>=y1 && ty<=y2 ){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
        

    }
    return 0;   
}