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
ll N,E,H,A,B,C;
ll fl=0;
ll tmp,x;
vector<ll>v,res;

void solve(){
    cin>>N>>E>>H>>A>>B>>C;
    //n  e H=c po pm pk
    rep(i,0,N+1){
        v.pb(i);
    }
    rep(i,0,N){
        ll lb=lower_bound(all(v),(2*N-E-2*i))- v.begin();
        ll up=upper_bound(all(v),(H-3*i))- v.begin()-1;
        
        if( up < lb || lb == N+1 ){
            continue;
        }  
        if(up == N+1 && (up+3*i)>H){
            continue;
        }

        if(C>A){
            if( lb < (N-i)){
                tmp=lb;
            }
            else{
                tmp=N-i;
            }
        }
        else{
            if( up < (N-i)){
                tmp=up;
            }
            else{
                tmp=N-i;
            }
        }
        x=N-tmp-i;
        if(tmp+2*i >= 2*N-E && (tmp+3*i) <=H){
            res.pb(A*x + B*i+ C*tmp);
        }
    }
    
    if(SZ(res)==0){
        cout<<-1<<endl;
    }
    else{
        sort(all(res));
        cout<<res[0]<<endl;
    }
    v.clear();
    res.clear();

    return;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    ll T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}