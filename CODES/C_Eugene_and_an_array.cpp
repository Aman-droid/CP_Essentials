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
    ll a[n+1],pr[n+1];
    rep(i,1,n){
        cin>>a[i];
    }
    pr[0]=0;
    pr[1]=a[1];
    rep(i,2,n){
        pr[i]=pr[i-1]+a[i];
    }
    ll ans=0;
    ll i=0,j=0;
    set<ll>st;
    st.insert(0);
    while(i<n){
        while(j<n && st.find(pr[j+1])==st.end()){
            j++;
            st.insert(pr[j]);
        }
        ans+=j-i;
        st.erase(pr[i]);
        i++;
    }
    cout<<ans<<endl;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    ll T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}