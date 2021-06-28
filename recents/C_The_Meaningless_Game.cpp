#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const int mxn=2e5;

// map<int,int>mp1,mp2;

// void pfac1(int N){
//     for(int i=2;i*i<=N;i++){
//         if(N%i==0){
//             int cnt=0;
//             while(N%i==0){
//                 cnt++;
//                 N=N/i;
//             }
//             mp1.insert({i,cnt});
//         }
//     }
//     if(N>1){
//         mp1.insert({N,1});
//     }
//     // for(auto it:mp){
//     //     cout<<it.ff<<" "<<it.ss<<endl;        
//     // }
// }

int cbrt(int N){
    int low=1,high=1e6;
    int res=-1;
    while(low<=high){
        int mid=(high+low)/2;
        //watch(mid);

        if(mid*mid*mid >= N){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}

void solve(){
    int a, b;cin>>a>>b;
    int fl=0;
    int N=a*b;
    int M = cbrt(N);
    //watch(M);
    if(M*M*M != N){
        cout<<"No"<<endl;
        return;
    }
    if(a%M==0 && b%M==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
