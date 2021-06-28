#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define vpll vector<pll>
#define SZ(x) ((ll)x.size())
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
    ll T=1;//cin>>T;
    while (T--){
        ll n,m,x,k;cin>>n>>k;
        ll a[n];
        rep(i,0,n-1){cin>>a[i];}
        ll i=0,j=0;
        ll sum=0;
        ll res=0;
        while(j<n){
            //watch2(i,j);
            sum+=a[j];
            //watch(sum);
            if(sum<=k){
                res=max(res,j-i+1);
                j++; 
            }
            else if(sum>k){
                while(sum>k){
                    sum=sum-a[i];
                    i++;
                }
                j++;
            }
        }
        cout<<res<<endl;
    }
    return 0;   
}