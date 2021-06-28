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

const int mxn=1e3;
int sumd[mxn+10];
int low[mxn+10];


void pre(){
    
    rep(i,1,mxn){
        low[i]=INF;
        sumd[i]=0;
    }
    // for(int i=1;i<=mxn;i++){
    //     for(int j=i;j<=mxn;j+=i){
    //         sumd[j]+=i;
    //     }
    // }
    for(int i=1;i<mxn;i++){
        for(int j=i;j<mxn;j+=i){
            sumd[j] +=i;
        }
    }

    rep(i,1,mxn){
        int x = sumd[i];
        low[x] = min(i,low[x]);
    }

    // for(int i=1;i<=mxn;i++){
    //     s[sumd[i]].insert(i);
    // }
}

void solve(){
    int c;cin>>c;
    if(low[c]==INF){
        cout<<"-1"<<endl;
    }
    else{
        cout<<low[c]<<endl;
    }
}

signed main() {
    FIO;
    pre();
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const ll mod=1e9+7;
// const int maxn=1e6+10;
// ll a[maxn],dp[maxn];
// vector<int>G[maxn];
// void init()
// {
//     for(int i=1;i<maxn;i++)
//     {
//         for(int j=i;j<maxn;j+=i)
//             G[j].push_back(i);
//     }
// }
