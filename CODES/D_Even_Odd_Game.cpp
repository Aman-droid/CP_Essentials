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
        ll n,m,x,y;cin>>n;
        ll ev=0,od=0;
        ll a[n];
        priority_queue<ll>q1,q2;
        rep(i,0,n-1){
            cin>>a[i];
            if(a[i]%2==0){
                ev++;
                q1.push(a[i]);
            }
            else{
                q2.push(a[i]);
                od++;
            }
        }
        if(n==1){
            if(ev==1)cout<<"Alice"<<endl;
            else cout<<"Tie"<<endl;
        }
        else if(od==n){
            cout<<"Bob"<<endl;
        }
        else if(ev==n){
            cout<<"Alice"<<endl;
        }
        else{
            ll s1=0,s2=0;
            rep(i,1,n){
                if(i%2==1){
                    x=0,y=0;
                    if(!q1.empty()){
                        x=q1.top();
                    }
                    if(!q2.empty()){
                        y=q2.top();
                    }
                    if(x>=y){
                        s1+=x;
                        q1.pop();
                    }
                    else
                        q2.pop();
                }
                else{
                    x=0,y=0;
                    if(!q1.empty()){
                        x=q1.top();
                    }
                    if(!q2.empty()){
                        y=q2.top();
                    }
                    if(y>=x){
                        s2+=y;
                        q2.pop();
                    }
                    else
                        q1.pop();
                }
            }
            if(s1==s2)
                cout<<"Tie"<<endl;
            else if(s1>s2)
                cout<<"Alice"<<endl;
            else{
                cout<<"Bob"<<endl;
            }   
            

        }

    }
    return 0;   
}