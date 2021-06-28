#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
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
    int T=1;//cin>>T;
    while (T--)
    {
        int n,x,y;cin>>n;
        int a[n];
        map<int,int>mp;
        map<int,int>mp2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int uq=0;
        int cnt=0;
        for(auto it :mp){
            if(it.ss==1)
                uq++;
            if(it.ss>2)
                cnt++;
        }
        if((uq%2==1 && cnt==0))
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cnt=0;
            if(uq%2==0)
            {
                rep(i,0,n-1){
                    if(cnt%2==0 && mp[a[i]]==1){
                        cout<<'A';
                        cnt++;
                    }
                    else if(cnt%2==1 && mp[a[i]]==1){
                        cout<<'B';
                        cnt++;
                    }
                    else
                        cout<<'B';
                    
                }
                cout<<endl;
            }
            else{
                cnt=0;
                int tmp;
                rep(i,0,n-1){
                    if(mp[a[i]]>2){
                        tmp=a[i];
                    }
                }
                int fl=0;
                rep(i,0,n-1){
                    if(cnt%2==0 && mp[a[i]]==1){
                        cout<<'A';
                        cnt++;
                    }
                    else if(cnt%2==1 && mp[a[i]]==1){
                        cout<<'B';
                        cnt++;
                    }
                    else if(fl==0 && a[i]==tmp){
                        cout<<'B';
                        fl=1;
                    }
                    else
                        cout<<'A';
                }
            }
        }
    }
}

