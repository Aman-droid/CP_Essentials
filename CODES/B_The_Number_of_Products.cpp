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
ll ck(ll n){
    if(n>0)return 1;
    else return -1;
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        ll a[n];
        rep(i,0,n-1){cin>>a[i];}
        ll pos[n],neg[n];
        pos[0]=(a[0]>0)?1:0;
        neg[0]=(a[0]<0)?1:0;
        rep(i,1,n-1){
            if(a[i]>0){
                pos[i]=1+pos[i-1];
                neg[i]=neg[i-1];
            }
            else{
                pos[i]=neg[i-1];
                neg[i]=1+pos[i-1];
            }
        }
        ll ans1=0,ans2=0;
        rep(i,0,n-1){
            ans1+=pos[i];
            ans2+=neg[i];
        }
        cout<<ans2<<" "<<ans1<<endl;
    }
    return 0;   
}