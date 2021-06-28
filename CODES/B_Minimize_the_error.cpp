#include<bits/stdc++.h>
#define ll long long 
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
    ll b,tmp,n,k1,k2;cin>>n>>k1>>k2;
    priority_queue<ll>Q;
    ll a[n+1];
    rep(i,1,n){
        cin>>a[i];
    }
    rep(i,1,n){
        cin>>b;
        tmp=abs(b-a[i]);
        Q.push(tmp);
    }
    tmp=k1+k2;
    ll cur;
    while(tmp--){
        cur=Q.top();
        Q.pop();
        if(cur==0)cur++;
        else cur--;
        Q.push(cur);
    }
    ll ans=0;
    while(!Q.empty()){
        cur=Q.top();
        Q.pop();
        ans+=cur*cur;        
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