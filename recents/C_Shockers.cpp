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
int a[26];
void solve(){

    for(int i=0;i<26;i++){a[i]=1;}
    ll n,cnt2=0;cin>>n;
    n--;

    while(n--){
        char c,cc;
        string s;cin>>c>>s;cc=c;
        ll cnt=0;
        for(int i=0;i<26;i++)cnt+=a[i];
        //cout<<cnt<<endl;
        
        if(cnt==1){
            if(c=='!'||c=='?')cnt2++;
            continue;
        }
 
        if(cc=='?'){
            a[s[0]-'a']=0;
        }
        else if(cc=='!'){
            for(int i=0;i<26;i++)
            {
                ll f=1;
                c='a'+i;
                for(int j=0;j<s.length();j++)
                    if(c==s[j])f=0;
                
                int k = c-'a';
                if(f==1)
                    a[k]=0;
            }
        }
        else{
            for(int i=0;i<s.length();i++)
            {
                a[s[i]-'a']=0;
            }
        }
    }
    string t;cin>>t;
    cout<<cnt2<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
} 
 
