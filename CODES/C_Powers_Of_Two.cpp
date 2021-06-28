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

int main()
{
	int n,k;cin>>n>>k;
    map<int,int>ans;
    queue<int>q;
    for(int i=0;i<31;i++)
    {
        if(n&(1<<i))
        {
            if(i>0)
                q.push(1<<i);
            ans[1<<i]++;
        }
    }
    if(SZ(ans)>k)
        cout<<"NO"<<endl;
    else
    {
        int cnt=ans.size();
        while(cnt< k & !q.empty())
        {
            int tmp=q.front();
            q.pop();
            ans[tmp]--;
            ans[tmp/2]+=2;
            if(tmp/2 > 1)
            {
                q.push(tmp/2);
                q.push(tmp/2);
            }
            cnt++;
        }
        if(cnt<k)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(auto it: ans)
            {
                while(it.second--)
                    cout<<it.first<<" ";

            }
        }
        
    }
    
}