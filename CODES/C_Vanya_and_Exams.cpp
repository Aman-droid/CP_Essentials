#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
/*bool comp(pll p1,pll p2)
{
    if(p1.ff != p2.ff)
        return p1.ff < p2.ff;
    else
    {
        return p1.ss <= p2.ss;   
    }
}*/

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--)
    {
        ll n,r,av,x,y;cin>>n>>r>>av;
        vector<pair<ll,ll>>vec;
        ll sum=0;
        rep(i,1,n){
            cin>>x>>y;
            vec.pb({y,x});
            sum+=x;
        }
        int fl=0;
        ll dif=(av*n) -sum;
        ll ans=0;
        sort(vec.begin(),vec.end());
        if(dif<=0){
            cout<<"0"<<endl;
        }
        else {
            rep(i,0,SZ(vec)-1){
                ll tmp=r-vec[i].ss;
                if(tmp+sum >= av*n){
                    ans+= ((av*n)-sum)*vec[i].ff;
                    break;
                }
                else{
                    ans+=tmp*vec[i].ff;
                    sum+=tmp;
                }
            }
            cout<<ans<<endl;
        }
    }
}

