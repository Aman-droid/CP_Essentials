#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
while(b>0){
    if(b&1){res=(res*a);b--;}
    a=(a*a);
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//
ll div(ll n){
    ll res=-1;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res=max(res,gcd(n,i));
            if(n/i !=n)
                res=max(res,gcd(n,n/i));
        }
        //watch(res);
    }
    return res;
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--)
    {
        ll n;cin>>n;
        if(((n+1) & n)==0){
            ll ans =div(n);
            cout<<ans<<endl;
        }
        else{
            //watch(n);
            ll tmp=log2(n);
            if(n&(n-1)==0){
                cout<<power(2,tmp)-1<<endl;
            }
            else{
                cout<<power(2,tmp+1)-1<<endl;
            }
        }
    }
}

