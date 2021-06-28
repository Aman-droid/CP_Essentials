#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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
    int T=1;//cin>>T;
    while (T--){
        ll n1,n2,n3;cin>>n1>>n2>>n3;
        vector<ll>v1(n1),v2(n2),v3(n3);
        ll s1=0,s2=0,s3=0;
        rep(i,0,n1-1){cin>>v1[i];s1+=v1[i];}
        rep(i,0,n2-1){cin>>v2[i];s2+=v2[i];}
        rep(i,0,n3-1){cin>>v3[i];s1+=v3[i];}
        
    }
    return 0;   
}