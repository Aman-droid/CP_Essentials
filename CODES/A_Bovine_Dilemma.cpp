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
set<int>s;
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        s.clear();
        int n,m,u,v;cin>>n;
        int a[n];
        rep(i,0,n-1){cin>>a[i];}
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        sort(a,a+n);
        rep(i,0,n-1){
            rep(j,i+1,n-1){
                s.insert(a[j]-a[i]);
            }
        }
        cout<<SZ(s)<<endl;
    }
    return 0;   
}