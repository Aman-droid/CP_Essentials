#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
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

/*ll upt(ll n) { 
    ll tmp = n; 
    while (n){ 
        ll k = n % 10;  
        if (k!=0 && tmp%k!=0) {
            tmp+=(k-(tmp%k));
            return tmp;
        } 
        n /= 10; 
    } 
    return tmp;
} */
/*ll a[10];
ll upt(ll n) {
    rep(i,1,9)
        a[i]=0;
    ll tmp = n; 
    while (n){ 
        ll k = n % 10;  
        a[k]=1;
        n /= 10; 
    } 
    for(ll i=2;i<=9;i++)
    {
        if(a[i]==1 && tmp%a[i]!=0){
            tmp+=(a[i]-(tmp%a[i]));
            return tmp;
        }
    }
    return tmp;
}*/

bool chk(ll n) { 
    ll tmp = n; 
    while (n) { 
        ll k = n % 10;  
        if (k!=0 && tmp%k!=0){
            return false;
        } 
        n /= 10; 
    } 
    return true;
} 

int main() {
    FIO;
    int T;cin>>T;
    while (T--)
    {
        ll n;cin>>n;
        ll tmp=n;
        while(1)
        {
            //watch(tmp);
            if(chk(n)==true){
                cout<<n<<endl;
                break;
            }
            else
                n++;
        }
    }
}

  