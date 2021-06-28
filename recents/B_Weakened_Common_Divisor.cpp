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

set<int>st;

void fact(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1)st.insert(n);
}

void solve(){
    int n;cin>>n;
    int a[n+1],b[n+1];
    rep(i,1,n){
        cin>>a[i]>>b[i];
    }
    fact(a[1]);
    fact(b[1]);
    int fl=0;
    for(auto it:st){
        fl=0;
        rep(i,1,n){
            if(a[i]%it!=0 && b[i]%it!=0){
                fl=1;
                break;
            }
        }
        if(fl==0){
            cout<<it<<endl;
            return ;
        }
    }
    cout<<"-1"<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
        
    }
    return 0;   
}