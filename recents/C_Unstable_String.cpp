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
    int n;
    string s;cin>>s;
    if(s=="0" || s=="1"){
        cout<<"1"<<endl;
        return;
    }
    n=SZ(s);
    int dp[n][2];
    rep(i,0,n-1){
        dp[i][0]=0;
        dp[i][1]=0;
    }
    if(s[0]=='0')dp[0][0]=1;
    else if(s[0]=='1')dp[0][1]=1;
    else{
        dp[0][0]=1;
        dp[0][1]=1;

    }
    
    rep(i,1,n-1){
        if(s[i]=='1'){
            dp[i][0]=0;
            if(dp[i-1][0]>0){
                dp[i][1]=dp[i-1][0]+1;
                dp[i-1][0]=0;
            }
            else{
                dp[i][1]=1;
            }
        }
        else if(s[i]=='0'){
            dp[i][1]=0;
            if(dp[i-1][1]>0){
                dp[i][0] = dp[i-1][1]+1;
                dp[i-1][1] = 0;
            }
            else{
                dp[i][0]=1;
            }
        }
        else{
            if(dp[i-1][1] > 0){
                dp[i][0] = dp[i-1][1]+1;
                dp[i-1][1] = 0;
            }
            else{
                dp[i][0]=1;
            }
            
            if(dp[i-1][0]>0){
                dp[i][1]=dp[i-1][0]+1;
                dp[i-1][0]=0;
            }
            else{
                dp[i][1]=1;
            }
        }
    }
    int ans = n;
    int tmp=0;
    // rep(i,0,n-1){
    //     cout<<dp[i][0]<<" ";
    // }
    // cout<<endl;
    // rep(i,0,n-1){
    //     cout<<dp[i][1]<<" ";
    // }
    // cout<<endl;
    rep(i,0,n-1){
        if(dp[i][0]>1){
            tmp = dp[i][0]-1;
            ans+= (tmp*(tmp+1))/2;
        }
        if(dp[i][1]>1){
            tmp = dp[i][1]-1;
            ans+= (tmp*(tmp+1))/2;
        }
    }
    int cnt = 0;

    rep(i,0,n-1){
        if(s[i]=='?'){
            int j=i;
            while(s[j] =='?' && j<n){
                j++;
            }
            j--;
            if(j-i+1>1){
                int tmp=j-i;
                cnt+=(tmp*(tmp+1))/2;
            }
            i=j;
        }
    }
    //watch(ans);
    //watch(cnt);
    ans=ans-cnt;
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}