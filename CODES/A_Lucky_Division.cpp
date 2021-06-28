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
bool solve(int n){
    while(n>0){
        int x=n%10;
        if(x!=4 && x!=7)
            return false;
        n=n/10;
    }
    return true;
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        bool res=false;
        rep(i,4,n){
            if((n%i)==0){
                res=solve(i);
                if(res==true)break;
            }
        }
        if(res)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;   
}