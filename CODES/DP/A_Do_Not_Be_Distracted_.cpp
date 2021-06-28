#include<bits/stdc++.h>
#define int long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pint pair<int,int>
#define pii pair<int,int>
#define vpint vector<pint>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (int)(1e18)
#define aint(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5+5;

//-------------POWER---------------------//
int power2(int x,int y){
    int res=1;
    while(y>0){
        if(y%2==1)res=(res*x);
        y=y/2;
        x=(x*x);
    }
    return res;
}
//-------------BINPOWER---------------------//
int power(int x,int y){
    int res=1;
    while(y>0)
    {
        if(y%2==1)res=(res*x)%mod;
        y=y/2;
        x=(x*x)%mod;
    }
    return res;
}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}

//----------FACTORIAL & NCR-----------------------//
int inv(int a)
{
return power(a,mod-2);
}

int fact[mxn];
int inr[mxn];
void pre()
{
    fact[0]=1;
    for(int i=1;i<mxn;i++)fact[i]=(fact[i-1]*i)%mod;
    inr[0]=1;
    for(int i=1;i<mxn;i++)inr[i]=inv(fact[i]);
}

int ncr(int n,int r)
{
    int a=(fact[n]*inr[r])%mod;
    int b=(a*inr[n-r])%mod;
    return b;
}

//-------------SPF---------------------//
//spf smallest prime factor upto MAX
//T==O(mxn)
int spf[mxn];
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < mxn; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < mxn; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
            spf[i] = i;
        }
    }
}
//-------------Sieve----------------------//
//Check number is prime or not upto Max
//O(n*log(log(n)))

bool prime[mxn+2];
void SOE()
{
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=mxn;p++)
    {
        if(prime[p]==true)
            for(int i=p*p;i<=mxn;i+=p)
                prime[i]=false;
    }
}
//----------------DIVISORS--------------------------------//
// Function to print the divisors.O(sqrt(n))
vector<int> Divisors(int n )
{
    vector<int> res;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                res.pb(i);
            else
            {
                res.pb(i);
                res.pb(n/i);
            }
        }
    }
    return res;
}
//------------prime factorization----------------------------//
set<pair<int,int>> res;
void pfac(int N){
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            int cnt=0;
            while(N%i==0){
                cnt++;
                N=N/i;
            }
            res.insert({i,cnt});
        }
    }
    if(N>1){
        res.insert({N,1});
    }
    for(auto it:res){
        cout<<it.ff<<" "<<it.ss<<endl;        
    }
}
//---------------------------------

void solve(){
    int n;cin>>n;
    map<int,int>mp;
    string s;cin>>s;
    int fl=0;
    mp[s[0]-'a']++;
    rep(i,1,n-1){
        int x=s[i]-'a';
        if(s[i]==s[i-1]){
            continue;
        }
        if(mp.count(x)){
            fl=1;
            break;
        }
        mp[x]++;
    }
    if(fl==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
