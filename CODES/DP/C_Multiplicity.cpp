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
set<int>s;
void div(int x,int n,int tmp){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if( i<=n && i<=tmp)
                s.insert(i);
            if( x/i <=n && x/i <=tmp)
                s.insert(x/i);
        }
        else if(i>tmp){
            break;
        }
    }    
}

void solve(){
    int n,x;cin>>n;
    int a[n+1];
    int dp[n+1];
    dp[0]=1;

    rep(i,1,n){
        dp[i]=0;
        cin>>a[i];
    }
    int  tmp=1,id;
    rep(i,1,n){
        s.clear();
        div(a[i],n,tmp);
        //watch2(tmp,i);
        for(auto it=s.rbegin();it!=s.rend();it++){
            id=*it;
            //watch(id);
            dp[id]=(dp[id]+dp[id-1])%mod;
        }
        if(s.count(tmp))tmp++;
    }
    int ans=0;
    rep(i,1,n){
        //cout<<dp[i]<<" ";
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<<endl;

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}