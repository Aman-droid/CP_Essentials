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
vector<int>vis;

int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        vis= vector<int>(n+1,0LL);          //blunder always check n or n+1
        unordered_map<ll,ll>mp;
        vector<ll>res;
        rep(i,1,n){
            cin>>x;
            mp[x]++;
        }
        for(auto it:mp){
            res.pb(it.ss);
        }
        sort(res.begin(),res.end(),greater<ll>());
        ll ans=0;
        for(auto it:res){
            ll x=it;
            ll res=-1;
            while(x>0){
                if(vis[x]==0){
                    res=x;
                    vis[res]=1;
                    break;
                }
                else x--;
            }
            if(res==-1)continue;
            else ans+=res;
        }
        cout<<ans<<endl;
    }
    return 0;   
}