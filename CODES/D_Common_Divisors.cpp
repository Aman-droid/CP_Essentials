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

//-------------------soln----------------------------//

bool oper(string & s1,string &s2,int n,int m,int x){
    rep(i,0,n-1){
        if(s1[i]!=s1[i%x])
            return false;
    }
    rep(i,0,m-1){
        if(s2[i]!=s2[i%x])
            return false;
    }
    rep(i,0,x-1){
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

void solve(){
    string s1,s2;cin>>s1>>s2;
    int n=SZ(s1);
    int m=SZ(s2);
    int mn=min(SZ(s1),SZ(s2));
    int ans=0;
    for(int i=1;i<=mn;i++){
        if((n%i)==0 && (m%i)==0){
            if(oper(s1,s2,n,m,i)){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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