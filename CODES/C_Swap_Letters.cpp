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
        int n;cin>>n;
        string s,t;cin>>s;cin>>t;
        vector<int>v1,v2;
        rep(i,0,n-1){
            if(s[i]=='a' && t[i]=='b')v1.pb(i+1);
            else if(s[i]=='b' && t[i]=='a')v2.pb(i+1);
        }
        if((SZ(v1)+SZ(v2))%2==1)cout<<-1<<'\n';
        else{
            vector<pii>res;
            if(SZ(v1)%2==1){
                res.pb({v1[0],v1[0]});
                res.pb({v1[0],v2[0]});
                for(int i=1;i<SZ(v1);i=i+2){
                    res.pb({v1[i],v1[i+1]});
                }
                for(int i=1;i<SZ(v2);i=i+2){
                    res.pb({v2[i],v2[i+1]});
                }
            }
            else{
                for(int i=0;i<SZ(v1);i=i+2){
                    res.pb({v1[i],v1[i+1]});
                }
                for(int i=0;i<SZ(v2);i=i+2){
                    res.pb({v2[i],v2[i+1]});
                }
            }
            cout<<SZ(res)<<endl;
            for(auto it:res){
                cout<<it.ff<<" "<<it.ss<<endl;
            }
        }
    }
    return 0;   
}