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
int main(){
    FIO;
    ll T=1;cin>>T;
    while(T--){
        int n,k;cin>>n>>k;
        string s1,s2;cin>>s1>>s2;
        string s[n];
        
        vector<int>cnt1(27,0),cnt2(27,0);
        for(int i=0;i<n;i++){
            cnt1[s1[i]-'a']++;
            cnt2[s2[i]-'a']++;
        }
        int fl=0;
        for(int i=0;i<26;i++){
            if(cnt1[i]<cnt2[i]){
                fl=1;
                break;
            }
            else if((cnt1[i]-cnt2[i])%k!=0){
                fl=1;
                break;
            }
            cnt1[i+1]+=cnt1[i]-cnt2[i];
        }
        if(fl)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}