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
ll n,q;
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        cin>>n>>q;
        vector<ll>a(n);
        vector<ll>b(n+1,0);
        for(auto &x:a)cin>>x;
        ll l,r;
        while(q--){
            cin>>l>>r;
            l--;
            r--;
            b[l]+=1;
            b[r+1]-=1;
        }
        ll c[n];
        c[0]=b[0];
        rep(i,1,n-1){
            c[i]=c[i-1]+b[i];
        }
        sort(a.begin(),a.end());
        sort(c,c+n);
        ll sum=0;
        rep(i,0,n-1){
            sum+=a[i]*1LL*c[i];
        }
        cout<<sum<<endl;
    }
    return 0;   
}