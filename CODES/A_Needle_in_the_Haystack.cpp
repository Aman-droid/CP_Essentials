#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
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
 
//calculate Hash value of any string
//value=s[0]*p^0 +s[1]*p^1 + s[2]*p^2 ......
//mod>=26(char set size) and prime 
ll getHash(string str)
{
	ll value = 0;
	ll p = 31;
	ll p_power = 1;
 
	for(char ch : str){
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}
    return value;
} 

//Get Hash of any substring using in 0(1)
void init(string str)
{
	ll p = 31;
	ll p_power = 1;
	inv[0] = 1;
	dp[0] = (str[0] - 'a' + 1);
  
	for(int i=1;i<str.size();i++)
	{
		char ch = str[i];
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
        dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}
//hash value of substring L to R
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
	int n , L , R , ans;
	bool fl = 0;
 
	while(cin>>n){
		cin>>sub;//substring
		cin>>s;//main string
        ll sub_hash = getHash(sub);
        init(s);
        fl=0;
		for(L=0 , R=sub.size()-1; R < s.size(); L++ , R++)
		{
			if(sub_hash == substringHash(L , R)){
			    cout<<L<<endl;
                fl=1;
            }
		}
        if(fl==0)
            cout<<endl;
	}
}