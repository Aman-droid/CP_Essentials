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
        int n,m;cin>>n>>m;
        //string s[n],t1[n],t2[n];
        char s[n][m],t1[n][m],t2[n][m];
        rep(i,0,n-1){
            rep(j,0,m-1){
                cin>>s[i][j];
            }
        }
        rep(i,0,n-1){
            rep(j,0,m-1){
                if((i+j)%2==0){
                     t1[i][j]='.';t2[i][j]='*';
                }
                else{
                    t1[i][j]='*';t2[i][j]='.';
                }
            }
        }
        int ans1=0,ans2=0;
        rep(i,0,n-1){
            rep(j,0,m-1){
                if(s[i][j]!=t1[i][j]){
                    ans1++;
                }
                if(s[i][j]!=t2[i][j]){
                    ans2++;
                }                
            }
        }
        if((n*m)%2==0){
            
            int ans=min(ans1,ans2);
            cout<<ans<<endl;
        }
        else{
            cout<<ans2<<endl;
        }
    }
    return 0;   
}