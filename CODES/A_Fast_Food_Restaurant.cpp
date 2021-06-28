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
    int a[3];
    rep(i,0,2){
        cin>>a[i];
    }
    sort(a,a+3,greater<int>());
    int ans=0;
    rep(i,0,2){
        if(a[i]>0){
            ans++;
            a[i]--;
        }
    }
    sort(a,a+3,greater<int>());
    if(a[0]>0 && a[1]>0){
        ans++;
        a[0]--;
        a[1]--;
    }
    if(a[1]>0 && a[2]>0){
        ans++;
        a[1]--;
        a[2]--;
    }
    if(a[2]>0 && a[0]>0){
        ans++;
        a[0]--;
        a[2]--;
    }
    sort(a,a+3,greater<int>());
    if(a[1]>0 && a[2]>0 && a[0]>0){
        ans++;
        a[0]--;
        a[2]--;
        a[1]--;
    }
    cout<<ans<<endl;
    return;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}