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

void solve(){
    ll a,b,f,k;cin>>a>>b>>f>>k;
    ll avail=b-f,need=2*a,ans=0;
    //watch2(b,f);
    if(b<f){
        cout<<-1<<endl;
        return;
    }
    else{
        ll i;
        for(i=1;i<=k-1;i++){
            if((i%2)==1)need=2*(a-f);
            else need=2*f;
            
            if(b<need){cout<<-1;return;}
            if(avail<need){
                ans++;
                avail=b-need;
            }
            else{
                avail=avail-need;
            }    
        }

        if(i%2==1){need=a-f;}
        else need=f;

        if(b<need){cout<<-1;return;}
        if(avail<need){
            ans++;
            avail=b-need;
        }
        cout<<ans<<endl;
    }
    return;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}