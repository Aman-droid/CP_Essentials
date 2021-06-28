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

void solve(){
    int n,x;cin>>n;
    int pos=-1;
    int nxt=-1;
    int mn=INF;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<mn){
            pos=i;
            mn=a[i];
        }
    }

    cout<<n-1<<endl;
    int cnt=a[pos];
    rep(j,pos+1,n-1){
        cout<<pos+1<<" "<<j+1<<" "<<a[pos]<<" "<<cnt+1<<endl;
        cnt++;
    }
    cnt=a[pos];
    for(int i=pos-1;i>=0;i--){
        cout<<pos+1<<" "<<i+1<<" "<<a[pos]<<" "<<cnt+1<<endl;
        cnt++;
    }    

}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}