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
        ll n,m,x;cin>>n;
        ll q[n];
        ll tmp=0;
        int fl=0;
        rep(i,1,n-1){
            cin>>q[i];
            if(q[i]==0)fl=1;
            tmp+=q[i]*(n-i);
        }
        if(fl==1){
            cout<<-1<<endl;
            continue;
        }
        ll p1=(n*(n+1))/2 -tmp;
        if((p1%n)!=0){
            cout<<"-1"<<endl;
            continue;
        }
        unordered_map<ll,ll>mp;
        p1=p1/n;
        vector<ll>res;
        res.pb(p1);
        tmp=p1;
        mp[p1]++;
        rep(i,2,n){
            tmp+=q[i-1];
            if(tmp<1 || tmp>n || mp.count(tmp)){
                fl=1;
                break;
            }
            mp[tmp]++;
            res.pb(tmp);
        }
        if(fl==0){
            for(ll it:res){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;   
}