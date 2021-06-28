#include<bits/stdc++.h>
#define ll long long
#define int long long 
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

const int mxn=2e5;

void solve(){
    string s;cin>>s;
    int n=SZ(s);
    int pr[n+2]={0},sf[n+2]={0};
    rep(i,1,n-1){
        pr[i]=pr[i-1];
        if(s[i-1]=='Q'){
            pr[i]=1+pr[i-1];
        }
    }
    for(int i=n;i>=1;i--){
        sf[i]=sf[i+1];
        if(s[i-1]=='Q'){
            sf[i]=1+sf[i+1];
        }
    }
    int ans=0;
    rep(i,1,n){
        if(s[i-1]=='A')
            ans+=pr[i]*sf[i];
    }
    cout<<ans<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}