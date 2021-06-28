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
#define mod 100
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
        double ans,y;cin>>y;
        double x=5.0;
        ans=exp(y*log(x));
        //ans=pow(5.0,y);
        string s=to_string(ans);
        //cout<<s<<endl;
        int n =SZ(s);
        //watch(n);
        
        int pos;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='0' && s[i]!='.'  ){
                pos=i;
                cout<<s[pos-1]<<s[pos]<<endl;
                break;
            }
        }
        //watch(pos);
        //cout<<s[pos-1]<<s[pos]<<endl;


    }
    return 0;   
}