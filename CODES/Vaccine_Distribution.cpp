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

int main() {
    int T;cin>>T;
    while (T--)
    {
        int n,d,y;cin>>n>>d;
        int x;
        int a1=0,a2=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x<=9 || x>=80)
                a1++;
            else 
                a2++;
        }
        int ans=0;
        ans+=a1/d;
        ans+=a2/d;
        if(a1%d!=0)
            ans++;
        if(a2%d!=0)
            ans++; 
        cout<<ans<<endl;
    }
}

