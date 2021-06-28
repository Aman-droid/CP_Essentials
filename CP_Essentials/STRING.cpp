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
ll getHash(string str)
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
	ll p = 31; //greater than charset to avoid collision
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
/*
// https://www.geeksforgeeks.org/longest-prefix-also-suffix/
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    return res; //(res > n/2)? n/2 : res; 
}

*/


