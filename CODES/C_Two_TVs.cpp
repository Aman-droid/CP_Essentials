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
bool comp(pll a,pll b){
    if(a.ff!=b.ff)return a.ff<b.ff;
    else return a.ss<b.ss;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n,m,x;cin>>n;
        vpll vec(n);
        stack<pll>A,B;
        A.push({-1,-1});
        B.push({-1,-1});
        for(auto &it:vec){
            cin>>it.ff>>it.ss;
        }
        sort(vec.begin(),vec.end(),comp);
        int fl=0;
        pll x1,x2;
        rep(i,0,n-1){
            //cout<<vec[i].ff<<" "<<vec[i].ss<<endl;
            x1=A.top();
            x2=B.top();
            if(vec[i].ff > x1.ss){
                A.push(vec[i]);
            }
            else if(vec[i].ff > x2.ss){
                B.push(vec[i]);
            }
            else{
                fl=1;
                break;
            }
        }
        if(fl==0)cout<<"YES";
        else cout<<"NO";
    }
    return 0;   
}