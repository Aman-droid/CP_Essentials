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

//sum(a,b)=xor(a,b)+2*AND(a,b)//

void solve(){
    ll u,v;cin>>u>>v;
    if(u>v){
        cout<<-1<<endl;
        return;
    }
    else if(u%2 != v%2){
        cout<<-1<<endl;
        return;
    }
    else if(u==v){
        if(u==0){
            cout<<u<<endl;
        }
        else{
            cout<<1<<endl;
            cout<<u<<endl;
        }
    }
    else{
        ll tmp=(v-u)/2;
        if(tmp&u){
            cout<<3<<endl;
            cout<<u<<" "<<tmp<<" "<<tmp<<endl;
        }
        else{
            cout<<2<<endl;
            cout<<(u^tmp)<<" "<<tmp<<endl;
        }
    }
    return;
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