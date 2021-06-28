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

bool chk(string expr) 
{   
    stack<char> s; 
    char x; 
  
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(' || expr[i]=='?')  
        {  
            s.push(expr[i]); 
            continue; 
        } 
  
        else if (s.empty()) 
            return false; 
  
        else if(expr[i]=='?'|| expr[i]==')') { 
            s.pop(); 
            //s.pop(); 
        } 
    }
    while(!s.empty()){
        if(s.top()=='?'){
            s.pop();
        }
        else 
            break;
    }
    return (s.empty()); 
} 
  
int main() {
    int T=1;cin>>T;
    while (T--)
    {
        string s;cin>>s;
        int n=s.length();
        if(n%2==1)
            cout<<"NO"<<endl;
        else 
        {
            if(chk(s))
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }

    }   
}

