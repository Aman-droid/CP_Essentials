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
const ll MAX=1005;
ll spf[MAX];
vector<ll>adj[MAX];
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
            spf[i] = i;
        }
    }
}

signed main() {
    FIO;
    sieve();
    int T=1;cin>>T;
    while (T--){
        int n;cin>>n;
        ll a[n];
        rep(i,1,1005)adj[i].clear();
        vector<int>col(1005,0);
        rep(i,0,n-1){
            cin>>a[i];
            adj[spf[a[i]]].pb(a[i]);
        }
        int cnt=0;
        rep(i,2,1005){
            if(SZ(adj[i])>0){
                cnt++;
                for(auto &x:adj[i])col[x]=cnt;
            }
        }
        cout<<cnt<<endl;
        rep(i,0,n-1){
            cout<<col[a[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;   
}