#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
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
//--------------------------------------------------------------------------------------------------------/
const ll mxn=1e7+5;
bool prime[mxn];
void SOE()
{
    memset(prime,true,sizeof(prime));
    for(ll p=2;p*p<=mxn;p++)
    {
        if(prime[p]==true)
            for(ll i=p*p;i<=mxn;i+=p)
                prime[i]=false;
    }
}

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n; cin>>n;
        //watch(n);
        SOE();
        prime[1]=true;
        vector<ll>res;
        for(ll i=1;i<mxn;i++){
            if(prime[i])
                res.pb(i);
        }
        //sort(res.begin(),res.end());
        //watch(SZ(res));

        for(ll i=0;i<n;i++){
            cout<<res[i]*n<<" ";
        }
        cout<<endl;
    }
    return 0;   
}