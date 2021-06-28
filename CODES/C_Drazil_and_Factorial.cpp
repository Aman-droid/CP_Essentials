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
    int T=1;//cin>>T;
    while (T--){
        int n,m,x;cin>>n;
        vector<int>res;
        string s;cin>>s;
        rep(i,0,n-1){
            x=s[i]-'0';
            //watch(x);
            if(x==1||x==0)continue;
            else if(x%2==1){
                if(x==9){res.pb(3);res.pb(3);res.pb(2);res.pb(7);}
                else res.pb(x);
            }
            else if(x==2)res.pb(x);
            else if(x==6){
                res.pb(5);res.pb(3);
            }
            else{
                if(x==4){res.pb(3);res.pb(2);res.pb(2);}
                if(x==8){res.pb(7);res.pb(2);res.pb(2);res.pb(2);}
            }
        }
        sort(res.rbegin(),res.rend());
        for(auto it:res)cout<<it;
        cout<<endl;
    }
    return 0;   
}