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
//a=a%mod;
while(b>0){
    if(b&1){res=(res*a);b--;}
    a=(a*a);
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--)
    {
        int fl=0;
        int n,x,y;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll cst=5e18;
        for(ll c=1;c<5e9;c++)
        {
            if(power(c,n-1)>1e14)
                break;
            ll tmp=0;
            for(ll i=0;i<n;i++){
                tmp+=abs(a[i]-power(c,i));
                if(tmp>1e14){
                    fl=1;
                    break;
                }
            }
            if(fl==1)
                break;
            //watch(c);
            //watch(tmp);
            cst=min(cst,tmp);
        }
        cout<<cst<<endl;
    }
}

