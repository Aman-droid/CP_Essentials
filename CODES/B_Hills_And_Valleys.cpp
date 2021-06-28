#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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
    FIO;
    int T=1;cin>>T;
    while (T--){
        ll n;cin>>n;
        ll a[n];
        vector<ll>h(n,0),v(n,0);
        rep(i,0,n-1){cin>>a[i];}
        if(n<3){
            cout<<"0"<<endl;
            continue;
        }
        ll ans=0,ans1=0,ans2=0;
        rep(i,1,n-2){
            if(a[i]>a[i-1] && a[i]>a[i+1]){h[i]=1;ans1++;}
            if(a[i]<a[i-1] && a[i]<a[i+1]){v[i]=1;ans2++;}
        }
        if(ans1+ans2==0){
            cout<<"0"<<endl;
            continue;
        }
        int fl=0;
        ans=ans1+ans2;
        rep(i,2,n-3){
            if(h[i]==1 && v[i-1]==1 &&v[i+1]==1){
                fl=1;
                ans=ans-3;
                cout<<ans<<endl;
                break;
            }
            else if(v[i]==1 && h[i-1]==1 && h[i+1]==1){
                fl=1;
                ans=ans-3;
                cout<<ans<<endl;
                break;
            }
        }
        if(fl==0){
            rep(i,1,n-2){
                if(h[i]==1 && v[i+1]==1){
                    fl=1;
                    ans=ans-2;
                    cout<<ans<<endl;
                    break;
                }
                else if(v[i]==1 && h[i+1]==1){
                    fl=1;
                    ans=ans-2;
                    cout<<ans<<endl;
                    break;
                }
            }
        }
        if(fl==0){
            ans--;
            cout<<ans<<endl;
        }
        
    }
    return 0;   
}