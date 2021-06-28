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
    int T=1;cin>>T;
    while (T--)
    {
        int cnt=0;
        int n;cin>>n;
        string s;cin>>s;
        vector<int>ans;
        rep(i,0,n-1)
        {
            int x;
            x=s[i]-'0';
            if(x%2==1){
                ans.pb(x);
            }
        }
        if(SZ(ans)>=2)
        {
            cout<<ans[0]<<ans[1]<<endl;
        }
        else
            cout<<"-1"<<endl;
    }
}

