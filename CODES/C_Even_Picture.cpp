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
const int mxn=5e3;
int dx[]={1,-1,0,0,};
int dy[]={0,0,-1,1,};
bool vis[mxn][mxn];
int main() {
    int T=1;//cin>>T;
    while (T--){
        int n;cin>>n;
        int x=3;
        int y=3;
        cout<<7+(n-1)*3<<endl;
        cout<<x<<" "<<y<<endl;
        cout<<x+1<<" "<<y<<endl;
        cout<<x-1<<" "<<y<<endl;
        cout<<x<<" "<<y+1<<endl;
        cout<<x<<" "<<y-1<<endl;
        cout<<x-1<<" "<<y-1<<endl;
        cout<<x+1<<" "<<y+1<<endl;
        rep(i,1,n-1){
            x=x+1;
            y=y+1;
            cout<<x<<" "<<y+1<<endl;
            cout<<x+1<<" "<<y<<endl;
            cout<<x+1<<" "<<y+1<<endl;
        }
        
    }
}

