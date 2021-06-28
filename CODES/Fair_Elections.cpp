#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
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
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,m;cin>>n>>m;
        ll a[n],b[m];
        ll s1=0,s2=0;
        rep(i,0,n-1){
            cin>>a[i];s1+=a[i];
        }
        rep(i,0,m-1){
            cin>>b[i];s2+=b[i];
        }
        sort(a,a+n);
        sort(b,b+m,greater<ll>());
        ll x=min(n,m);
        int fl=0;
        if(s1>s2){
            cout<<"0"<<endl;
            continue;
        }
        ll ans=0;
        rep(i,0,x-1){
            ll tmp=b[i]-a[i];
            if(tmp>0){
                s1+=tmp;
                s2-=tmp;
                ans++;
            }
            if(s1>s2){
                fl=1;
                cout<<ans<<endl;
                break;
            }         
        }
        if(fl==0){
            cout<<"-1"<<endl;
        }


    }
    return 0;   
}