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
ll ar[3];
ll I[3][3],T[3][3];

void mul(ll A[3][3],ll B[3][3], ll dim)
{
    ll res[dim+1][dim+1];
    rep(i,1,dim){
        rep(j,1,dim){
            res[i][j]=0;
            rep(k,1,dim){
                ll x=A[i][k]*B[k][j]%mod;
                res[i][j]+=x;
            }
        }
    }
    rep(i,1,dim)
        rep(j,1,dim)
            A[i][j]=res[i][j];
}
ll fibn(ll n)
{
    if(n<=2)
        return ar[n];
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;
    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;
    n=n-1;
    while(n)
    {
        if(n%2==1)
            mul(I,T,2),n--;
        else 
            mul(T,T,2),n/=2;
    }
    ll x=(ar[1]*I[1][1]+ar[2]*I[2][1])%mod;
    return x;
}
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--)
    {
        ll n;
        cin>>ar[1]>>ar[2]>>n;
        n++;
        cout<<fibn(n)<<endl;
    }
}

