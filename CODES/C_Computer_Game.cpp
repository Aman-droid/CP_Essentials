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
ll k,n,a,b;
bool chk(ll x){
    if(x*a+(n-x)*b<k)return true;
    else 
        return false;
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        cin>>k>>n>>a>>b;
        if(k-(n*b)<=0){
            cout<<"-1"<<endl;
            continue;
        }
        ll res=-1;
        ll l=0,h=n;
        while(l<=h){
            ll mid=(l+h)/2;
            if(chk(mid)==true){
                res=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(res==-1)
            cout<<"-1"<<endl;
        else {
            cout<<res<<endl;
        }
        

    }
    return 0;   
}