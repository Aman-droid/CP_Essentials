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
    map<int,int>mp1,mp2;
    int x[3],y[3];
    rep(i,0,2){
        cin>>x[i]>>y[i];
        mp1[x[i]]++;
        mp2[y[i]]++;
    }
    int mx=1;
    for(auto it:mp1)mx=max(mx,it.ss);
    for(auto it:mp2)mx=max(mx,it.ss);
    if(mx==1){
        cout<<3<<endl;
    }

    else if(mx==2){
        //cout<<2<<endl;

        vector<int>yy;
        vector<int>xx;
        
        int fl=0;
        rep(i,0,2){
            if(mp1[x[i]]==2){
                yy.pb(y[i]);
                fl=1;
            }
            else{
                xx.pb(y[i]);
            }
        }
        if(fl==1){
            if(yy[1]<yy[0])swap(yy[0],yy[1]);
            if(xx[0]> yy[0] && xx[0]<yy[1]){
                cout<<3<<endl;
                return;
            }
        }

        fl=0;
        xx.clear();
        yy.clear();
        rep(i,0,2){
            if(mp2[y[i]]==2){
                yy.pb(x[i]);
                fl=1;
            }
            else{
                xx.pb(x[i]);
            }
        }
        if(fl==1){
            if(yy[1]<yy[0])swap(yy[0],yy[1]);
            if(xx[0]> yy[0] && xx[0]<yy[1]){
                cout<<3<<endl;
                return;
            }
        }
        cout<<2<<endl;

    }
    else{
        cout<<1<<endl;
    }
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}