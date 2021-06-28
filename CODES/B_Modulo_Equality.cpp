#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
ll n,m;
ll a[2500],b[2500];
bool chk(int j,ll dif ){
    rep(i,0,n-1){
        if((a[i]+dif)%m!=b[((i+j)%n)])
            return false;
    }
    return true;    
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--)
    {
        cin>>n>>m;
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,n-1)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int fl=0;
        ll ans=INT_MAX;
        rep(j,0,n-1){
            ll dif;
            if(b[j]>=a[0])
                 dif=b[j]-a[0];
            else 
                dif=m+b[j]-a[0];
           // watch(chk(j,dif));
            if(chk(j,dif)==true){
                ans=min(ans,dif); 
            }    
        }
        cout<<ans<<endl;

    }
}

