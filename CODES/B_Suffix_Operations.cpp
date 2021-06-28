#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pii pair<ll,ll>
#define SZ(x) ((ll)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
    ll T;cin>>T;
    while (T--)
    {
        ll n;cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        ll x=0;
        rep(i,1,n-1)
        {
            x+= abs(a[i]-a[i-1]);
            //cout<<x<<endl;
        }
        ll ans=x;

        ans-= abs(a[1]-a[0]);
       
        rep(i,1,n-1)
        {
            ll res=x;
            res-=abs(a[i]-a[i-1]);
            if(i!=n-1)
            {
                res-=abs(a[i]-a[i+1]);
                res+=abs(a[i+1]-a[i-1]);
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;



    }
}

