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

ll inv(ll a){
    return power(a,mod-2);
}
ll fact[200007];
ll inr[200007];

void pre()
{
    fact[0]=1;
    for(ll i=1;i<=200005;i++)fact[i]=(fact[i-1]*i)%mod;
    inr[0]=1;
    for(ll i=1;i<=200005;i++)inr[i]=inv(fact[i]);
}

ll ncr(ll n,ll r)
{
    ll a=(fact[n]*inr[r])%mod;
    ll b=(a*inr[n-r])%mod;
    return b;
}
const int mxn=2e5;

void solve(){
    int n ;cin>>n;
    int a[n];
    int val;
    unordered_map<int,int>mp;
    
    rep(i,0,n-1){
        cin>>a[i];
        mp[a[i]]++;
    }
    val=a[0];
    rep(i,0,n-1){
        val=val&a[i];
    }
    int val2=val;
    int fl=0;
    rep(i,0,n-1){
        val2= val2 & a[i];
        if(val2 != val){
            fl=1;
            break;
        }
    }

    if(fl==1){
        cout<<"0"<<endl;
        return;
    }

    //watch(val);
    if(mp.count(val)){
        if(mp[val]>=2){
            int cnt=mp[val];
            int ans=ncr(cnt,2)*2;
            ans=ans*fact[n-2];
            cout<<ans<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    else{
        cout<<"0"<<endl;
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

