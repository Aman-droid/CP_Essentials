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
bool chk(vector<pll> &vec,ll k ,ll n){
    ll sum=0;
    bool res=true;
    rep(i,0,k){
        sum+=vec[i].ff;
    }
    rep(i,k+1,n-1){
        if(sum>=vec[i].ff){
            sum+=vec[i].ff;
        }
        else{
            res=false;
            break;
        }
    }
    return res;
}
ll solve(vector<pll> &vec,ll n){
    ll l=0;
    ll h=n-1;
    ll pos=n-1;
    while(l<=h){
        ll mid=(l+h)/2;
        //watch(mid);
        if(chk(vec,mid,n)==true){
           // watch2(mid,n);
            pos=mid;
            h=mid-1;
        }
        else{
            l=mid+1;    
        }
    }
    return pos;
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n,x;cin>>n;
        vector<pll>v;
        rep(i,1,n){
            cin>>x;
            v.pb({x,i});
        }
        sort(v.begin(),v.end());
        ll p=solve(v,n);
        vector<ll>ans;
        rep(i,p,n-1){
            ans.pb(v[i].ss);
        }
        sort(ans.begin(),ans.end());
        cout<<SZ(ans)<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }       
    return 0;   
}