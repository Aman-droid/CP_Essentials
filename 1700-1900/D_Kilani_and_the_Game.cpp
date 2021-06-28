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
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; 
const int mxn = 1000 + 3;
char A[mxn][mxn];
int level[mxn][mxn];
int n, m, p;
int s[10], cnt[10];
 
queue<pair<int, int>> q[10];
 
int rem = 0;
set<int> over;
 
void MultiSourceBfs(int idx){
    vector<pii> srs;
    int i, j, k;
    while(!q[idx].empty()){
        srs.pb(q[idx].front()); 
        q[idx].pop();
    }
    queue<pii> new_q;
    bool fl = 0;
 
    for(auto x : srs){
        new_q.push(x);
    }
    while(!new_q.empty()){
        pii t = new_q.front(); new_q.pop();

        if(level[t.ff][t.ss] == s[idx]){
            level[t.ff][t.ss] = 0;
            q[idx].push(t); 
            continue;
        }

        for(int i = 0; i < 4; i++){
            int x = t.ff + dx[i];
            int y = t.ss + dy[i];
            if(x >= 1 and y >= 1 and x <= n and y <= m and A[x][y] == '.'){
                A[x][y] = A[t.ff][t.ss];
                rem--;
                fl=1;
                level[x][y] = 1 + level[t.ff][t.ss];
                new_q.push(make_pair(x, y)); 
            }
        }
    }
    if(fl==0){
        over.insert(idx);
    }
}
 
void solve(){
    cin >> n >> m >> p;

    rep(i,1,p)cin>>s[i];
    rep(i,1,n){
        string s; 
        cin >> s; s = '*' + s;

        for(int j = 1; j <= m; j++){
            A[i][j] = s[j];
            if(s[j] >= '1' and s[j] <= '9'){
                q[s[j] - '0'].push({i, j});
            }   
            else if(s[j] == '.')
                rem++;
        }
    }
 
    int i = 1;
 
    while(rem>0 && over.size() < p){
        MultiSourceBfs(i);
        if(i == p)
            i = 1;
        else
            i++;
    }
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i][j] >= '1' and A[i][j] <= '9'){
                cnt[A[i][j] - '0']++;
            }
        }
    }
 
    for(i = 1; i <= p; i++){
        cout << cnt[i] << ' ';
    }
    cout <<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        solve();
    }
    return 0;   
}