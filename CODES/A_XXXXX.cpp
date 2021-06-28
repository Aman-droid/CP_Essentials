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
int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int n,m,x;cin>>n>>x;
        int a[n];
        int sum=0;
        rep(i,0,n-1){cin>>a[i];sum+=a[i];}
        int i=0,j=n;
        int ans=-1,ans2=-1;
        if(sum%x!=0){cout<<n<<endl;continue;}
        rep(i,0,n-1){
            if(a[i]%x!=0){
                ans=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]%x!=0){
                ans2=i;
                break;
            }
        }
        //watch2(ans,ans2);
        if(ans==-1 && ans2==-1){
            cout<<-1<<endl;
        }
        else{
            int res=max(ans+1,n-1-ans);
            int res1=max(ans2,n-ans2);
            int ans3=max(res,res1);
            cout<<ans3<<endl;
        }
    }
    return 0;   
}