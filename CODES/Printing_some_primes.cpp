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
const ll mxn=1e8;
bool prime[mxn];
void SOE(){
    //memset(prime,true,sizeof(prime));
    for(ll i=2;i*i<=mxn;i++){
        if(prime[i]==false){
            for(ll p=i*i;p<=mxn;p+=i){
                prime[p]=true;
            }
        }
    }
} 
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        SOE();
        ll cnt=0;
        for(ll i=2;i<=mxn;i++){
            if(prime[i]==false){
                cnt++;
                if(cnt%100==1){
                    cout<<i<<endl;
                }
            }
        }
    }
    return 0;   
}