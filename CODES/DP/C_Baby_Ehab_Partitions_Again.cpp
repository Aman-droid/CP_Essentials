
#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}

bool knap(int a[],int n,int sum){
    
    bool dp[n+1][sum+1];

    rep(i,0,n){
        rep(j,0,sum){
            if(j==0)dp[i][j]=true;

            else if(i==0) dp[i][j]=false;
            
            else{
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    return dp[n][sum];

}

void solve(){
    int n;cin>>n;
    int a[n];
    int sum=0;

    rep(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%2==1){
        cout<<"0"<<endl;
        return;   
    }
    int sum2=sum/2;

    bool res= knap(a,n,sum2);
    
    if(res){
        cout<<"1"<<endl;
        int pos=-1;
        while(1){
            int gc=a[0];
            rep(i,0,n-1){
                gc=gcd(gc,a[i]);
            }
            rep(i,0,n-1){
                a[i]=a[i]/gc;
                if(a[i]%2==1){
                    pos=i;
                    break;
                }
            }
            if(pos!=-1)break;
        }
        cout<<pos+1<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}