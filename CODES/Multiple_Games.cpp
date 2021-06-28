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
const ll mxn=1e6+10;

int main() {
    FIO;
    ll T=1;cin>>T;
    while (T--){
        ll n,q,m,l,r,p;cin>>n>>q>>m;
        ll a[n];
        ll cnt[m+1];
        rep(i,0,m)cnt[i]=0; //g
        rep(i,0,n-1){cin>>a[i];}
        map<pair<ll,ll>,ll>mp;
        
        while(q--){
            cin>>l>>r;
            l--;
            r--;

            if(a[l]<=m && a[r]>m){
                cnt[a[l]]++;
                cnt[m+1]--;
            }
            else if(a[r]<=m){
                cnt[a[l]]++;
                cnt[m+1]--;
                mp[{a[l],a[r]}]++;
            }
        }

        ll L,R;
        for(auto it: mp){
            L = it.ff.ff; 
            R = it.ff.ss;
            l = it.ss;
            //cout<<L<<" "<<R<<" "<<l<<endl;
            cnt[R+L]-=l;
            cnt[R+2*L]+=l;
            ll cur=R+2*L;
            while(cur+R <= m){
                cur=cur+R;
                cnt[cur]-=l;
                cnt[cur+L]+=l;
                cur=cur+L;
            }
        }

        for(ll i=1;i<=m;i++){
            cnt[i]+=cnt[i-1];
            //cout<<cnt<<" ";
        }
        ll mxg=0;

        for(ll i=0;i<=m;i++){
            mxg=max(cnt[i],mxg);
        }
        cout<<mxg<<endl;
    }
    return 0;   
}

//if(a[l]>m)continue;