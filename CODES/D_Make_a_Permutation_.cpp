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
const ll mxn=3e5;
ll cnt[mxn]={0};
ll cnt2[mxn]={0};
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        ll n;cin>>n;
        ll a[n+1];
        ll tmp;
        vector<ll>vec;
        rep(i,1,n){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(ll i=n;i>=1;i--){
            if(cnt[i]==0){
                vec.pb(i);
            }
        }  
        ll ans=0;      
        rep(i,1,n){
            if(cnt[a[i]]==1)continue;
            if(cnt[a[i]]>1){
                tmp=vec.back();
                if(cnt2[a[i]]==1){
                    ans++;
                    cnt[a[i]]--;
                    a[i]=tmp;
                    cnt[tmp]++;
                    vec.pop_back();
                }
                if(tmp<a[i]){ //taking tmp
                    ans++;
                    cnt[a[i]]--;
                    a[i]=tmp;
                    cnt[tmp]++;
                    vec.pop_back();
                }
                else if(tmp>a[i]){ //taking a[i]
                    cnt2[a[i]]=1;
                }
            }
        }
        cout<<ans<<endl;
        rep(i,1,n){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
       
