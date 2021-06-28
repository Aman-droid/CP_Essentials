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
        ll n;cin>>n;
        ll a[n];
        rep(i,0,n-1)cin>>a[i];

        ll ans = n - 1;
        map<ll, ll> cnt; 
        rep(i,0,n-1){
            bool fl = true;
            for(ll j = 0; j < i; ++j){
                cnt[a[j]]++;
                if(cnt[a[j]] == 2){
                    fl = false;
                    break;
                }
            }
            ll sf = n;
            for(ll j = n - 1; j >= i; j--){
                cnt[a[j]]++;
                if(cnt[a[j]] == 1){
                    sf = j;
                }
                else break;
            }
            if(fl){
                ans = min(ans, sf - i);
            }
            cnt.clear();
        }
        cout << ans << '\n';
    }
    return 0;   
}
