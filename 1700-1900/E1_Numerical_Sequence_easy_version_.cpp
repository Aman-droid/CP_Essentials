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
vector<int>v;
int tmp;
string seq;
void pre(){
    seq="*";
    int x=1;
    while(SZ(seq)<=1e5){
        seq+=to_string(x);
        x++;
    }
}

int get(int x){
    int sum=0;
    int pw = 1;
    while(pw<=x){
        sum += x-pw+1;
        pw=pw*10;
    }
    return sum;
}

void init(){
    int x=1,prev=0;
    v.pb(0);
    while(1){
        tmp=get(x);
        tmp+=prev;
        if(tmp>1e9){
            break;
        }
        v.pb(tmp);
        x++;
        prev=tmp;
    }
}

void solve(){
    watch(SZ(v));
    int k,pos,prev;cin>>k;
    auto it=lower_bound(all(v),k);
    pos= it-v.begin();
    prev=pos-1;
    k=k-v[prev];
    //watch(pos);
    //watch(k);
    int len = get(pos);
    //watch(len);
    char ans=seq[k];
    cout<<ans<<endl;



}
signed main() {
    FIO;
    init();
    pre();
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}