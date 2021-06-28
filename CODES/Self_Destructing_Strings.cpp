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
        //int n,x,y;cin>>n;
        string s;cin>>s;
        int n=s.length();
        int cnt=0;
        rep(i,0,n-1){
            if(s[i]=='0')cnt++;
        }
        if(n%2==1 ||cnt==0 ||cnt==n)cout<<"-1"<<endl;
        else if(cnt==(n/2))cout<<"0"<<endl;
        else{
            if(cnt<n/2){
                cnt=n/2 - cnt;
                cout<<cnt<<endl;
            }
            else{
                cnt=cnt-n/2;
                cout<<cnt<<endl;
            }
        }
        
    }
}

