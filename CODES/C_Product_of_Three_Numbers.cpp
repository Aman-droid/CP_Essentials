#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

int main() {
    FIO;
    int T=1;cin>>T;
    while (T--)
    {
        ll n,x,y;cin>>n;
        ll a=0,b=0,c=0;
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                a=i;
                n=n/i;
                break;
            }
        } 
        for(ll i=2;i*i<=n;i++){
            if(n%i==0 && i!=a){
                b=i;
                n=n/i;
                break;
            }
        }
        if(a==0|| b==0 ||n==1 ||n==a||n==b)
             cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<n<<endl;        
        }
               
    }
}

