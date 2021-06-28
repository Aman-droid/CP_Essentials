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
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int m=1e5;
        int n;cin>>n;
        int x,y,l,u,r,d;
        int xlg=-m,xhg=m;
        int ylg=-m,yhg=m;
        int xl,xh,yl,yh;
        int fl=0;
        rep(i,1,n){
            cin>>x>>y>>l>>u>>r>>d;
            xl= (l==1)?-m:x;
            xh= (r==1)?m:x;
            yl= (d==1)?-m:y;
            yh= (u==1)?m:y;
            if(ylg>yh || xlg>xh || yhg<yl || xhg<xl){
                fl=1;
            }
            else if(fl==0){
                xlg=max(xlg,xl);   
                ylg=max(ylg,yl);   
                xhg=min(xhg,xh);   
                yhg=min(yhg,yh);   
            }
        }
        if(fl==1){
            cout<<"0"<<endl;
        }
        else{
            cout<<"1 "<<xlg<<" "<<ylg<<endl;
        }       
    }
    return 0;   
}