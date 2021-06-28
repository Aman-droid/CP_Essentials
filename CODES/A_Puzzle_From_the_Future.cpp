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

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        string a, b;cin>>b;
        int k = -1;
        for(int i=0;i<n;i++){
            if(b[i]=='0' && k!=1){
                a+= '1';
                k = 1;
            }
            else if(b[i]=='0' && k==1){
                a+= '0';
                k = 0;
            }
            else if(b[i]=='1' && k!=2){
                a+= '1';
                k = 2;
            }
            else if(b[i]=='1' && k==2){
                a+= '0';
                k = 1;
            }
        }
        cout<<a<<"\n";
    }
    return 0;
}