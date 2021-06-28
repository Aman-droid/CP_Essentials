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
#define pf push_frontal
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
/*
	//NUMBER THEORY:-

ll power(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y%2==1)res=(res*x)%mod;
		y=y/2;
		x=(x*x)%mod;
	}
	return res;
}

ll inv(ll a)
{
return power(a,mod-2);
}

ll fact[2000007];
ll inr[2000007];
void pre()
{
	fact[0]=1;
	for(ll i=1;i<=2000005;i++)fact[i]=(fact[i-1]*i)%mod;
	inr[0]=1;
	for(ll i=1;i<=2000005;i++)inr[i]=inv(fact[i]);
}

ll ncr(ll n,ll r)
{
	ll a=(fact[n]*inr[r])%mod;
	ll b=(a*inr[n-r])%mod;
	return b;
}

//-------------------------------------------------------------------------------------------------------------
//spf smallest prime factor upto MAX
//T==O(MAX)
ll MAX=10000001;
ll spf[10000001];
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
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

bool prime[1000005];
void SOE()
{
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=1000000;p++)
    {
        if(prime[p]==true)
            for(int i=p*p;i<=1000000;i+=p)
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
//prime factorization
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

*/

/*
	STRINGS:-

ll dp[1000001];
ll inv[1000001];
 
ll power(ll a , ll n)
{
	ll result = 1;
 
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
 
		n >>= 1;
		a = (a * a) % mod;
	}
 
	return result;
}
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
 
//calculate Hash value of any string
//value=s[0]*p^0 +s[1]*p^1 + s[2]*p^2 ......
//mod>=26(char set size) and prime 
/*ll getHash(string str)
{
	ll value = 0;
	ll p = 31;
	ll p_power = 1;
 
	for(char ch : str)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
    return value;
} 


//Get Hash of any substring using in 0(1)
void init(string input_string)
{
	ll p = 31;
	ll p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);
  
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
 
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
 
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}
 

ll substringHash(int L , int R)
{
	int result = dp[R];
 
	if(L > 0) 
        result = (result - dp[L-1] + mod) % mod;
    
    result = (result * inv[L]) % mod;
    return result;
}
 
int main()
{
	string s , sub;
	int n , L , R , answer;
	bool flag = false;
 
	while(cin>>n){
		cin>>sub;//substring
		cin>>s;//main string
 
		ll sub_hash = getHash(sub);
        
        init(s);
		for(L=0 , R=sub.size()-1; R < s.size(); L++ , R++)
		{
			if(sub_hash == substringHash(L , R))
			cout<<L<<endl;
		}
        cout<<endl;
	}
}
*/



/*
	//DISJOINT

const int mxn=2e5;int par[mxn];int R[mxn];
//FIND function 
int find(int n){if(n==par[n])return n;else return find(par[n]);}

//FIND function with ******path compression******
int find2(int a){if(par[a]<0) return a;else{int x=find(par[a]);par[a]=x;return x;}}

//UNION:- join two different sets
void Union(int a,int b){int a=find(a);int b=find(b);if(a==b)return;else par[a]=b;}

//Union by rank node having larger number of childs will be parent 
void merge(int a,int b){a=find(a);b=find(b);if(a==b)return;
	if(R[a]>R[b]){	//a will be parent 
		par[b]=a;R[a]+=R[b];}
	else {	//b will be parent 
		par[a]=b;R[b]+=R[a];}
}
int parent[100001];
 
int find(int a)
{
	while(parent[a] > 0)
		a = parent[a];
 
	return a;
}
 
void Union(int a , int b)
{
	parent[a] += parent[b];		//adding size of set b to set a
	parent[b] = a;				//making a , parent of new set
}
  
int main()
{
	int n , m , a , b;
	cin>>n>>m;
 	for(int i=1;i<=n;i++)
		parent[i] = -1;		//initializing
 
	while(m--){
		cin>>a>>b;
		a = find(a) , b = find(b);
		if(a != b) Union(a , b);
	}
 	long long int res = 1;
 
	for(int i=1;i<=n;i++)
	if(parent[i] < 0)
	res = (res * abs(parent[i])) % 1000000007;
 	cout<<res;
}

*/

