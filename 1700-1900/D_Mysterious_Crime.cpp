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
// ll getHash(string str)
// {
// 	ll value = 0;
// 	ll p = 31;
// 	ll p_power = 1;
 
// 	for(char ch : str)
// 	{
// 		value = (value + (ch - 'a' + 1)*p_power) % mod;
// 		p_power = (p_power * p) % mod;
// 	}
//     return value;
// } 


// //Get Hash of any substring using in 0(1)
// void init(string input_string)
// {
// 	ll p = 31; //greater than charset to avoid collision
// 	ll p_power = 1;
// 	inv[0] = 1;
// 	dp[0] = (input_string[0] - 'a' + 1);
  
// 	for(int i=1;i<input_string.size();i++)
// 	{
// 		char ch = input_string[i];
 
// 		p_power = (p_power * p) % mod;
// 		inv[i] = power(p_power , mod - 2);
 
// 		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
// 	}
// }
 
// ll substringHash(int L , int R)
// {
// 	int result = dp[R];
 
// 	if(L > 0) 
//         result = (result - dp[L-1] + mod) % mod;
    
//     result = (result * inv[L]) % mod;
//     return result;
// }
// void solve(){
//     int n,m;cin>>n>>m;
//     string s[m];
//     rep(i,0,m-1){
//         cin>>s[i];
//     }
//     rep(i,0,n-1){

//     }
// }

/*KMP
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}*/


//when comparing permutaion we can renumber all according to us......

const int mxn=2e5;
int a[12][mxn];
int pr[mxn];
int mn[mxn];
void solve(){
    int n,m;cin>>n>>m;
    
    rep(i,1,m){
        rep(j,1,n){
            cin>>a[i][j];
        }
    }

    rep(j,1,n){
        pr[a[1][j]]=j;
    }

    rep(i,1,m){
        rep(j,1,n){
            a[i][j]=pr[a[i][j]];
            //cout<<a[i][j]<<" ";
        }
        //cout<<endl;
    }
    rep(i,1,n){
        mn[i]=n;
    }
    
    rep(i,1,m){
        int cur=1;
        rep(j,1,n){

            if(cur<j)cur++;

            while(cur<n && a[i][cur+1]==a[i][cur]+1){
                cur++;
            }

            mn[a[i][j]] = min(mn[a[i][j]],a[i][cur]);            
        }
    }

    int ans=0;
    int i=1;
    int cur;
    while(i <= n){
        cur = mn[i]- i+1;
        ans+= ((cur*(cur+1))/2);
        i=mn[i]+1;
    }
    cout<<ans<<endl;

}


signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
