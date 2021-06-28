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
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll a1,a2,a3;
        ll n ,k;cin>>n>>k;
        while(k>3){
            cout<<"1"<<" ";
            n--;
            k--;
        }
        if(n%3==0){
            cout<<n/3<<" "<<n/3<<" "<<n/3<<endl;
        }
        else{
            if(n%2==1){
                cout<<"1"<<" "<<n/2<<" "<<n/2<<endl;
            }
            else{
                ll tmp=n/2;
                if(tmp%2==0){
                   cout<<n/2<<" "<<tmp/2<<" "<<tmp/2<<endl;                     
                }
                else{
                    tmp--;
                    cout<<2<<" "<<tmp<<" "<<tmp<<endl;
                }
            }
        }
    }
    return 0;   
}
