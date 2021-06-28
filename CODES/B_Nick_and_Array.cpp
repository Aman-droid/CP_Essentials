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
    int T=1;//cin>>T;
    while (T--)
    {
        ll n;cin>>n;
        ll a[n];
        ll neg=0,pos=0;
        ll mx=INT_MIN;
        rep(i,0,n-1){
            cin>>a[i];
            mx=max(mx,a[i]);
            if(a[i]<0)
                neg++;
            else 
                pos++;
        }
        //sort(a,a+n);
        rep(i,0,n-1){
            if(a[i]>=0)
                a[i]=-a[i]-1;
        }
        if(n%2==1){
            ll mx=-1,pos;
            rep(i,0,n-1){
                if(abs(a[i])>mx){
                    mx=abs(a[i]);
                    pos=i;
                }
            }
            a[pos]=-a[pos]-1;
            
        }
        rep(i,0,n-1)
            cout<<a[i]<<" ";
        cout<<'\n';
    }
}

