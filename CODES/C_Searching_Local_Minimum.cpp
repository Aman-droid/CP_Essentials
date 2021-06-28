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
void solve()
{
    int n;cin>>n;
    int low = 1;
    int high= n;
    int a,b,c;
    if(n==1){
        cout<<"?"<<" "<<n<<endl;cin>>b;
        cout<<"!"<<" "<<n<<endl;
        return;
    }
    cout<<"?"<<" "<<"1"<<endl;cin>>a;
    cout<<"?"<<" "<<"2"<<endl;cin>>b;
    if(a<b){
        cout<<"!"<<" "<<1<<endl;
        return;
    }
    cout<<"?"<<" "<<n<<endl;cin>>a;
    cout<<"?"<<" "<<n-1<<endl;cin>>b;
    if(a<b){
        cout<<"!"<<" "<<n<<endl;
        return;
    }   
    while(low <=high){
        int mid=(high+low)/2;
        cout<<"?"<<" "<<mid-1<<endl;cin>>a;
        cout<<"?"<<" "<<mid  <<endl;cin>>b;
        cout<<"?"<<" "<<mid+1<<endl;cin>>c;
        if(b<a && b<c){
            cout<<"!"<<" "<<mid<<endl;
            return;
        }
        else if(a<b){
            high=mid;
        }
        else if(c<b){
            low=mid;
        }
    }
}
signed main() {
    //FIO;
    int T=1;//cin>>T;
    while (T--){
        solve();
    }
    return 0;   
}