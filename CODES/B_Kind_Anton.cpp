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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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

//-------------------soln-----------------------------//

void solve(){
    ll n;cin>>n;
    ll a[n],b[n];
    rep(i,0,n-1){
        cin>>a[i];
    }
    rep(i,0,n-1){
        cin>>b[i];
    }
    ll cnt0=0,cnt1=0,cnt2=0;
    if(a[0]==1)cnt1++;
    if(a[0]==-1)cnt2++;
    if(a[0]==0)cnt0++;
    int fl=0;
    if(a[0]!=b[0]){
        cout<<"NO"<<endl;
        return;
    }
    else{
        rep(i,1,n-1){
            if(b[i]>a[i] && cnt1<=0){
                fl=1;
                cout<<"NO"<<endl;
                return;
            }
            else if(b[i]<a[i] && cnt2<=0){
                fl=1;
                cout<<"NO"<<endl;
                return;
            }

            if(a[i]==1)cnt1++;
            if(a[i]==-1)cnt2++;
        }
        if(fl==0){
            cout<<"YES"<<endl;
        }
    }
    return;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}