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
const int mxn=2e5;
vector<int> adj[mxn];
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,m,x,k;cin>>n>>k;
        int a[n];
        int cnt,mx=-1;
        rep(i,0,n-1){
            cin>>a[i];
            mx=max(a[i],mx);
        }
        //watch(mx);
        rep(i,0,n-1){
            cnt=0;
            x=a[i];
            while(x>0){
                //watch2(x,i);
                adj[x].pb(cnt);
                cnt++;
                x= x/2;
            }
            //watch(x);
            adj[x].pb(cnt);
        }
        ll ans=INT_MAX;
        for(ll i=mx;i>=0;i--){
            ll tmp=0;
            if(adj[i].size()>=k){
                sort(adj[i].begin(),adj[i].end());
                for(ll j=0;j<=k-1;j++){
                    tmp+=adj[i][j];
                }
                ans=min(tmp,ans);
            }
        } 
        cout<<ans<<endl;       
    }
    return 0;   
}