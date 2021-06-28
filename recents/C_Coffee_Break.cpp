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

void solve(){
    ll n,m,d,x;cin>>n>>m>>d;
    multiset<pair<ll,ll>>s;

    rep(i,1,n){
        cin>>x;
        s.insert({x,i});
    }

    ll cnt=0;

    pair<ll,ll> cur={0,0};
    vector<pair<ll,ll>>res;
    while(!s.empty()){
        cnt++;
        cur=*s.begin();
        res.pb({cur.ss,cnt});
        s.erase(s.begin());

        while(1){
            const pair<ll,ll>pr={cur.ff+d+1LL,0LL};
            auto it=s.lower_bound(pr);
            if((*it).ff<=m){
                cur=*it;
                res.pb({cur.ss,cnt});
                s.erase(it);
            }
            else{
                break;
            }
        }
    }
    cout<<cnt<<endl;
    sort(all(res));
    for(auto it :res){
        cout<<it.ss<<" ";
    }
    cout<<endl;   

}

signed main() {
    FIO;
    int T=1;///cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}