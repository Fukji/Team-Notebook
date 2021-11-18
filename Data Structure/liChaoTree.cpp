ll n, c, h[200005];
ll DP[200005] = {0};
int tree[4000005] = {0};
pll L[200005];

ll getVal(ll x, pll line){
	return line.fi * x + line.se;
}

void input(){
	cin >> n >> c;
	UU(i, 1, n) cin >> h[i];
}

void update(int idx, int l, int r, int now){
	int m = l + r >> 1;
	bool Left = (getVal(l, L[now]) < getVal(l, L[tree[idx]]));
	bool smaller = (getVal(m, L[now]) < getVal(m, L[tree[idx]]));

	if(smaller){
		swap(tree[idx], now);
	}

	if(l == r) return ;
	if(Left != smaller){
		update(idx * 2, l, m, now);
	}
	else{
		update(idx * 2 + 1, m + 1, r, now);
	}
}

ll query(int idx, int l, int r, ll x){
	ll res = getVal(x, L[tree[idx]]);
	if(l == r) return res;

	int m = l + r >> 1;
	if(x <= m) return min(res, query(idx * 2, l, m, x));
	return min(res, query(idx * 2 + 1, m + 1, r, x));
}

void solve(){
	L[0] = {0, 1e18};
	UU(i, 1, n)
	{
		DP[i] = (i == 1 ? 0 : h[i] * h[i] + c + query(1, 1, 1e6, h[i]));
		L[i] = {-2 * h[i], h[i] * h[i] + DP[i]};
		update(1, 1, 1e6, i);
	}

	cout << DP[n] << endl;
}
