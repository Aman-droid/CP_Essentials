//https://codeforces.com/contest/1272/problem/E

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<int> a;
vector<int> ans;
vector<vector<int>> g;
//multisources BFS==>shortest distance of vectex from any sources....
//take all sources put all dis=0
//then push into the queue
//then run normal bfs  
void bfs(const vector<int> &start, const vector<int> &end) {
	vector<int> d(n, INF);
	queue<int> q;
	for (auto v : start) {
		d[v] = 0;
		q.push(v);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	for (auto v : end) {
		if (d[v] != INF) {
			ans[v] = d[v];
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	a = vector<int>(n);
	g = vector<vector<int>>(n);
	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] & 1) odd.push_back(i);
		else even.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int lf = i - a[i];
		int rg = i + a[i];
		if (0 <= lf) g[lf].push_back(i);
		if (rg < n) g[rg].push_back(i);
	}
	
	ans = vector<int>(n, -1);
	bfs(odd, even);
	bfs(even, odd);
	for (auto it : ans) cout << it << " ";
	cout << endl;
	
	return 0;
}



/*
//https://codeforces.com/contest/1105/problem/D

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
*/