#include<bits/stdc++.h>
#define ll long long 
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
const ll INF=5e15;
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

int main(){
    FIO;
    ll T=1;//cin>>T;
    while(T--)
    {
        ll n,m;cin>>n>>m;
        ll a[n],b[m];
        rep(i,0,n-1)cin>>a[i];
        rep(i,0,m-1)cin>>b[i];
        sort(a,a+n);
        sort(b,b+m);
        ll ans=-INF;
        rep(i,0,n-1){
            ll lo=lower_bound(b,b+m,a[i])-b;
            ll x=INF;
            if(a[i]<=b[0])
                x=b[0]-a[i];
            else if(a[i]>=b[m-1])
                x=a[i]-b[m-1];
            else{
                x=b[lo]-a[i];
                x=min(x,a[i]-b[lo-1]);
            }
            ans=max(ans,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
 