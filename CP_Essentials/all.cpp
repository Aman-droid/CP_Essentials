//WA
    // edge cases like n=1. 
    // overflow
    // global variables for every test case.
//Run time error 
    // division by zero.
    // array bounds.
    // Time Complexicity.
//TLE
    // uncomment that #define endl '\n' line
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------------------------------------------------------------------------------------------------------------
ll power(ll x,ll y){
	ll res=1;
	while(y>0){
		if(y%2==1)res=(res*x)%mod;
		y=y/2;
		x=(x*x)%mod;
	}
	return res;
}

const ll mxn=2e6;
ll inv(ll a){
    return power(a,mod-2);
}

ll fac[mxn];
ll inr[mxn];
void fact(){
	fac[0]=1;
	for(ll i=1;i<mxn;i++)fac[i]=(fac[i-1]*i)%mod;
	inr[0]=1;
	for(ll i=1;i<mxn;i++)inr[i]=inv(fac[i]);
}

ll ncr(ll n,ll r){
	ll a=(fac[n]*inr[r])%mod;
	ll b=(a*inr[n-r])%mod;
	return b;
}

//-------------------------------------------------------------------------------------------------------------
//spf smallest prime factor upto MAX
//T==O(MAX)
ll spf[mxn];
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < mxn; i++) 
    {
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
//----------------------------------------------------------------------------------------------------------
//Check number is prime or not upto Max
//O(n*log(log(n)))

bool prime[mxn+1];
void SOE()
{
    //memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=mxn;p++)
    {
        if(prime[p]==true)
            for(int i=p*p;i<=mxn;i+=p)
                prime[i]=false;
    }
}
//---------------------------------------------------------------------------------------------------------------------------

// Function to print the divisors.O(sqrt(n))
vll Divisors(ll n )
{
    vll res;
    for(ll i=1;i<=sqrt(n);i++)
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
//----------------------------------------------------------------------------------------------------------------------------
//prime factorization O(sqrt(N));
set<pair<ll,ll>> res;
void pfac(ll N){

    for(ll i=2;i*i<=N;i++){
        if(N%i==0){
            ll cnt=0;
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

// Prime factorisation O(logn)
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFact(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
//---------------------------------
int n,q;
vector<vector<int >>vec;
int main()
{
	ll T=1;cin>>T;
	while(T--)
	{
        int n,d;cin>>n>>d;
        int ans=0;
        string s ;cin>>s;
        int i=0;

	}
	return 0;
}


