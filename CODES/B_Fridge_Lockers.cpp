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
//--------------------------------------------------------------------------------------------------------//
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,u,v;cin>>n>>m;
        int a[n+1];
        ll sum=0;
        rep(i,1,n){cin>>a[i];sum+=a[i];}
        if(n!=m || n==2){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<sum*2<<endl;
        rep(i,1,n){
            if(i==n)
                cout<<n<<" "<<"1"<<endl;
            else 
                cout<<i<<" "<<i+1<<endl;
        }

    }
    return 0;   
}