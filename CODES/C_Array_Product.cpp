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
signed main() {
    FIO;
    ll T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        vector<ll>s0,sn,sp;
        vector<pll>v;
        ll pos=-1;
        ll mx=-mod;
        rep(i,1,n){
            cin>>x;
            if(x==0) s0.pb(i);
            else if(x<0){ 
                sn.pb(i);
                if(x>mx){
                    pos=i;
                    mx=x;
                }
            }
            else sp.pb(i);
        }
        int cnt=0;
        //watch(SZ(sn));
        if(SZ(sn)%2==1){   //odd
                cnt=0;
                if(SZ(s0)>0){
                    rep(i,0,SZ(s0)-2){
                        cout<<"1 "<<s0[i]<<" "<<s0[i+1]<<endl;
                        cnt++;
                    }
                    cout<<"1 "<<s0[SZ(s0)-1]<<" "<<pos<<endl;
                    cnt++;
                }
                if(cnt==(n-1))break;
                cout<<"2 "<<pos<<endl;
                vector<ll>res;
                for(auto x:sp)res.pb(x);
                for(auto x:sn){
                    if(x!=pos)
                        res.pb(x);
                }
                sort(res.begin(),res.end());
                for(ll i=0;i<SZ(res)-1;i++){
                    cout<<"1 "<<res[i]<<" "<<res[i+1]<<endl;
                }
            
            // else{
            //     //cout<<"2 "<<pos<<endl;
            //     vector<ll>res;
            //     for(auto x:s0)res.pb(x);
            //     for(auto x:sn){
            //         if(x!=pos)
            //             res.pb(x);
            //     }
            //     sort(res.begin(),res.end());
            //     for(ll i=0;i<SZ(res)-1;i++){
            //         cout<<"1 "<<res[i]<<" "<<res[i+1]<<endl;
            //     }
            // }
        }
        else{
            cnt=0;
            if(SZ(s0)>0){
                rep(i,0,SZ(s0)-2){
                    cout<<"1 "<<s0[i]<<" "<<s0[i+1]<<endl;
                    cnt++;
                }
                if(cnt==(n-1))break;
                cout<<"2 "<<s0[SZ(s0)-1]<<endl;
            }
            vector<ll>res;
            for(auto x:sn)res.pb(x);
            for(auto x:sp)res.pb(x);
            sort(res.begin(),res.end());
            for(ll i=0;i<SZ(res)-1;i++){
                cout<<"1 "<<res[i]<<" "<<res[i+1]<<endl;
            }
        }
    }
    return 0;   
}