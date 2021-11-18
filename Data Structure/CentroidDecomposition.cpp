vector<int> to[2][50005];
int n, k, dep[50005];
int sz[50005];
bool done[50005];
vector<int> sub[50005];
int sparse[50005][16];

void input(){
	cin >> n >> k;
	for(int i = 1 ; i < n ; ++i){
		int u, v;
		cin >> u >> v;
		to[0][u].pb(v);
		to[0][v].pb(u);
	}
}
ll ans = 0;
int get(int a, int b){
	int res = 0;
	if(dep[a] < dep[b]) swap(a, b);
	for(int x = 15 ; x >= 0 ; --x){
		if(dep[a] - (1<<x) >= dep[b]){
			a = sparse[a][x];
			res += (1<<x);
		}
	}
	if(a == b) return res;
	for(int x = 15 ; x >= 0 ; --x){
		if(sparse[a][x] != sparse[b][x]){
			a = sparse[a][x];
			b = sparse[b][x];
			res += (1<<(x + 1));
		}
	}
	return res + 2;
}
ll num[505];
void solve(int u){
	for(int x = 0 ; x <= k ; ++x)
		num[x] = 0;
	for(int x : sub[u]) if(get(u, x) <= k) ++num[get(u, x)];
	ans += num[k];
	for(int x = 1 ; x <= k / 2 ; ++x){
		if(x * 2 == k) ans += num[x] * (num[x] - 1) / 2;
		else ans += num[x] * num[k - x];
	}
	if(k > 2) for(int &v : to[1][u]){
		for(int x = 0 ; x <= k ; ++x){
			num[x] = 0;
		for(int x : sub[v]) if(get(u, x) <= k) ++num[get(u, x)];
		for(int x = 1 ; x <= k / 2 ; ++x){
			if(x * 2 == k) ans -= num[x] * (num[x] - 1) / 2;
			else ans -= num[x] * num[k - x];
		}
	}
	for(int &v : to[1][u])
		solve(v);
}

void getSize(int u, int p = -1){
	sz[u] = 1;
	for(int &v : to[0][u]){
		if(v == p || done[v]) continue;
		getSize(v, u);
		sz[u] += sz[v];
	}
}

int getCent(int num, int u, int p = -1){
	for(int &v : to[0][u]){
		if(v == p || done[v]) continue;
		if(sz[v] > num / 2) return getCent(num, v, u);
	}
	return u;
}
int build(int u, int p = -1, int step = 0){
	getSize(u);
	int cent = getCent(sz[u], u, p);
	done[cent] = true;

	for(int &v : to[0][cent])
		if(!done[v])
			to[1][cent].pb(build(v, cent, step + 1));

	return cent;
}
void getSub(int u, int p = -1){
	sub[u].pb(u);
	for(int &v : to[1][u]){
		if(v == p) continue;	
		getSub(v, u);
		sub[u].insert(sub[u].end(), sub[v].begin(), sub[v].end());
	}
}
void buildLca(){
	for(int x = 1 ; x < 16 ; ++x){
		for(int i = 1 ; i <= n ; ++i){
			sparse[i][x] = sparse[sparse[i][x - 1]][x - 1];
		}
	}
}
void dfs(int u, int p = -1, int step = 0){
	dep[u] = step;
	for(int &v : to[0][u])
		if(p != v){
			sparse[v][0] = u;
			dfs(v, u, step + 1);
		}
}
void Ahoy(){
	int root = build(1);
	getSub(root);

	dfs(1);
	sparse[1][0] = 1;
	buildLca();

	solve(root);
	cout << ans << endl;
}
