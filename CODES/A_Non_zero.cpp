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
    int n;cin>>n;
    int sum=0;
    int cnt=0;
    int a[n];
    rep(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
        if(a[i]==0)cnt++;
    }
    int ans=0;
    if(cnt==0){
        if(sum==0){
            cout<<1<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        }
    }
    else{
        if(sum==0){
            cout<<cnt<<endl;
            return;
        }
        else{
            if(sum+cnt==0){
                cout<<cnt+1<<endl;
            }
            else{
                cout<<cnt<<endl;
            }
        }
    }
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