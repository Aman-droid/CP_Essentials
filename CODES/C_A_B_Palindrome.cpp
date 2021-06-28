// #include<bits/stdc++.h>
// #define ll long long
// #define int long long 
// #define endl '\n'
// #define rep(i,a,b)  for(int i=a;i<=b;i++)
// #define pll pair<ll,ll>
// #define pii pair<int,int>
// #define vpll vector<pll>
// #define SZ(x) ((int)x.size())
// #define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
// #define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
// #define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
// #define pb push_back
// #define pf push_front
// #define ff first
// #define ss second
// #define mod 1000000007
// #define INF (ll)(1e18)
// #define all(c) (c).begin(),(c).end()

// using namespace std;
// ll power(ll a, ll b){//a^b
// ll res=1;
// a=a%mod;
// while(b>0){
//     if(b&1){res=(res*a)%mod;b--;}
//     a=(a*a)%mod;
//     b>>=1;
// }
//     return res;
// }
// ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
// //-------------------soln-----------------------------//

// const int mxn=2e5;

// void solve(){
//     int n,a,b;cin>>a>>b;
//     string s;cin>>s;
//     n=SZ(s);
//     if(a+b>n){
//         cout<<"-1"<<endl;
//         return;
//     }
//     int fl=0;
//     rep(i,0,n/2){
//         if(i == n/2 ){
//             if(n%2==1){
//                 if(s[i]=='0')a--;       
//                 else if(s[i]=='1')b--;       
//                 else{
//                     if(a>=b){
//                         a--;
//                         s[i]='0';
//                     }
//                     else{
//                         s[i]='1';
//                         b--;
//                     }
//                 }
//             }       
//         }
//         else if(s[i]!='?' && s[n-i-1]!='?' && s[i]!=s[n-1-i]){
//             fl=1;
//             break;
//         }
//         else if(s[i]== '?' && s[n-i-1]!='?'){
//             s[i]=s[n-i-1];
//             if(s[i]=='0')a=a-2;
//             else b=b-2;
//         }
//         else if(s[i]!= '?' && s[n-i-1]=='?'){
//             s[n-i-1]=s[i];
//             if(s[i]=='0') a=a-2;
//             else b=b-2;
//         }
//         



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

void solve(){
    int n,a,b;cin>>a>>b;
    string s;cin>>s;
    n=SZ(s);
    if(a+b>n){
        cout<<"-1"<<endl;
        return;
    }
    int fl=0;
    int A,B;
    rep(i,0,n/2){
        if(i == n/2 ){
            if(n%2==1){
                if(s[i]=='0')a--;       
                else if(s[i]=='1')b--;       
            }       
        }
        else if(s[i]!='?' && s[n-i-1]!='?' && s[i]!=s[n-1-i]){
            fl=1;
            break;
        }
        else if(s[i]== '?' && s[n-i-1]!='?'){
            s[i]=s[n-i-1];
            if(s[i]=='0')a=a-2;
            else b=b-2;
        }
        else if(s[i]!= '?' && s[n-i-1]=='?'){
            s[n-i-1]=s[i];
            if(s[i]=='0') a=a-2;
            else b=b-2;
        }
        else if(s[i]!= '?' && s[n-i-1]!='?'){
            if(s[i]=='0')a=a-2;
            else b=b-2;
        }
    }

    rep(i,0,n/2){
        if(i == n/2 ){
            if(n%2==1){
                if(s[i]=='?'){
                    if(a>b){
                        s[i]='0';
                        a--;
                    }
                    else{
                        s[i]='1';
                        b--;
                    }
                }                
            }       
        }

        else if(s[i]== '?' && s[n-i-1]=='?'){
            if(a>=b){
                a=a-2;
                s[n-i-1]='0';
                s[i]='0';
            }
            else{
                b=b-2;
                s[n-i-1]='1';
                s[i]='1';
            }
        }
        //watch2(a,b);
        if(a<0 || b<0 ){
            fl=1;
            break;
        } 
     }
        
    
    if(fl==1){
        cout<<"-1"<<endl;
    }
    else{
        if(a==0 && b==0){
            cout<<s<<endl;
        }
        else{
                cout<<"-1"<<endl;
        }
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