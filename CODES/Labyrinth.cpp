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
 
/*int vis[1005][1005];
vector<string> t;
int dx[] = { 1 , -1 , 0, 0};
int dy[] = { 0 , 0, 1 , -1};
int n,m;
int fl;
vector<pair<int,int>>ans;
bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(vis[x][y]==1)
        return false;
    return  true;
}
 
void dfs_grid(int x,int y){
    vis[x][y]=1;
    ans.pb({x,y});
    for(int i=0;i<4;i++){
        int xn = x + dx[i] ;
        int yn = y + dy[i] ;
        if(isValid(xn,yn) && t[xn][yn]=='.'){
            dfs_grid(xn,yn);
        }
        else if(isValid(xn,yn) && t[xn][yn]=='B'){
            fl =1;
            return;
        }
        
    }
}*/

typedef tuple<int, int, int> iii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<iii> q;
int main()
{
    int n, m;
    cin >> n >> m;
    vvc a(n);
    vvi b(n);
    int ai, aj, bi, bj;
    for (int i = 0; i < n; i++) {
        a[i] = vc(m);
        b[i] = vi(m, -1);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                ai = i; aj = j;
            } 
            else if (a[i][j] == 'B') {
                bi = i; bj = j;
            }
        }
    }
    q q;
    q.push(make_tuple(ai, aj, 0));
    while (!q.empty()) {
        int i, j, k;
        tie(i, j, k) = q.front();
        q.pop();
        if (b[i][j] != -1) continue;
        b[i][j] = k;
        if (i == bi && j == bj) {
            cout << "YES\n" << b[i][j] << endl;
            string p;
            while (i != ai || j != aj) {
                if (i > 0 && b[i - 1][j] == k - 1) {
                    p.push_back('D');
                    i--;
                }
                else if (i < n - 1 && b[i + 1][j] == k - 1) {
                    p.push_back('U');
                    i++;
                } 
                else if (j > 0 && b[i][j - 1] == k - 1) {
                    p.push_back('R');
                    j--;
                } 
                else {
                    p.push_back('L');
                    j++;
                }
                k--;
            }
            reverse(p.begin(), p.end());
            cout << p << endl;
            return 0;
        }
         if (i > 0 && a[i - 1][j] != '#' && b[i - 1][j] == -1)
        q.push(make_tuple(i - 1, j, k + 1));
        if (i < n - 1 && a[i + 1][j] != '#' && b[i + 1][j] == -1)
        q.push(make_tuple(i + 1, j, k + 1));
    if (j > 0 && a[i][j - 1] != '#' && b[i][j - 1] == -1)
      q.push(make_tuple(i, j - 1, k + 1));
    if (j < m - 1 && a[i][j + 1] != '#' && b[i][j + 1] == -1)
      q.push(make_tuple(i, j + 1, k + 1));
    }
  cout << "NO\n";
}