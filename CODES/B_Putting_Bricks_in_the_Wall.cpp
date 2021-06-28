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
        int n;cin>>n;
        string s[n];
        rep(i,0,n-1){
            cin>>s[i];
        }
        int a12=s[0][1]-'0';
        int a21=s[1][0]-'0';
        int an=s[n-1][n-2]-'0';
        int bn=s[n-2][n-1]-'0';
        if(a12==a21){
            if(an==bn && an!=a12)
                cout<<"0"<<endl;
            else if(an==bn && an==a12){
                cout<<"2"<<endl;
                cout<<n<<" "<<n-1<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
            else{
                cout<<"1"<<endl;
                if(an==a12)
                    cout<<n<<" "<<n-1<<endl;
                if(bn==a12)
                    cout<<n-1<<" "<<n<<endl;
            }
        }
        else{
            if(an==bn)
            {
                cout<<"1"<<endl;
                if(an==a12)
                    cout<<1<<" "<<2<<endl;
                if(an==a21)
                    cout<<2<<" "<<1<<endl;
            }
            else 
            {
                cout<<"2"<<endl;
                if(a12==1)
                    cout<<1<<" "<<2<<endl;
                if(a21==1)
                    cout<<2<<" "<<1<<endl;
                if(an==0)
                    cout<<n<<" "<<n-1<<endl;
                if(bn==0)
                    cout<<n-1<<" "<<n<<endl;
                
            }
        
        }
        

    }
}

