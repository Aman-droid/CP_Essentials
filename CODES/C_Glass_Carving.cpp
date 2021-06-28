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
set<ll>H,W;
multiset<ll>mh,mw;
ll w,tmp,val,h,n;

int main() {
    FIO;
    cin>>w>>h>>n;
    H.insert(0);H.insert(h);
    W.insert(0);W.insert(w);

    mh.insert(h);mw.insert(w);
    char ch;
    ll x,y,ans,ans1,ans2=-1;
    rep(i,1,n){
        cin>>ch;
        cin>>tmp;
        if(ch == 'H'){
            auto high= H.lower_bound(tmp); 
            y=*high;
            high--;
            x=*high;
            mh.erase(mh.find(y-x));
            mh.insert(y-tmp);
            mh.insert(tmp-x);
            H.insert(tmp);
        }
        else{
            auto high=W.lower_bound(tmp); 
            y=(*high);
            high--;
            x=(*high);
            mw.erase(mw.find(y-x));
            mw.insert(y-tmp);
            mw.insert(tmp-x);
            W.insert(tmp);
        }
        ans1=(*mh.rbegin());
        ans2=(*mw.rbegin());
        ans=ans1*ans2;
        cout<<ans<<endl;
    }
    return 0;   
}



