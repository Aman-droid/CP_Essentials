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
int main() {
    //FIO;
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        string s[n];
        rep(i,0,n-1){
            cin>>s[i];
        }
        int m=s[0].length();
        int ans=1;
        if(n==1){
            rep(i,0,m-1){
                if(s[0][i]=='2')
                    ans*=2;
            }
            cout<<ans<<endl;
            continue;
        }
        rep(i,0,m-1){
            int fl=0;
            char tmp=s[0][i];
            rep(j,1,n-1){
                if(s[j][i]!=tmp || s[j][i]=='2'){
                    fl=1;
                    break;
                }
            }
            //watch(fl);
            if(fl)
                ans=(ans*2)%mod;
        }
        cout<<ans<<endl;

    }
    return 0;   
}