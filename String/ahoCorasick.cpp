//Aho-Corasick for patter searching
//Output, 1 if exist
const int K = 256;
struct Vertex {
	int next[K];
	bool leaf = false;
	int p = -1;
	char pch;
	int link = -1;
	int go[K];
	vector<int> idx;
	Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
		fill(begin(next), end(next), -1);
		fill(begin(go), end(go), -1);
	}
};
int ans[10005];
vector<Vertex> t(1);
string s;
void add_string(int num){
	int v = 0;
	for(char ch : s){
		int c = ch;
		if(t[v].next[c] == -1){
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}
		v = t[v].next[c];
	}
    t[v].leaf = true;
    t[v].idx.pb(num);
}
int go(int v, char ch);
int get_link(int v){
	if(t[v].link == -1){
		if(v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go(get_link(t[v].p), t[v].pch);
	}
	for(int &x : t[v].idx) {
		ans[x] = 1;
	}
	return t[v].link;
}
int go(int v, char ch){
	int c = ch;
	if(t[v].go[c] == -1){
		if(t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
	}
	for(int &x : t[v].idx) {
		ans[x] = 1;
	}
	return t[v].go[c];
} 
string text, str;
int q;
void solve(){
	t.clear();
	t.assign(1, Vertex());
	cin >> text;
	cin >> q;
	for(int i = 1 ; i <= q ; ++i){
		cin >> s;
		add_string(i);
		ans[i] = 0;
	}
	int node = 0;
	char last = text[0];
	for(int i = 0 ; i < text.length() ; ++i){
		char c = text[i];
		last = c;
		node = go(node, c);
		for(int x = 0 ; x < t[node].idx.size()){
			ans[t[node].idx[x]] = 1;
		}
	}
	if(node != 0){
		go(node, last);
		while(node > 0){
			node = get_link(node);
			UP(i, 0, t[node].idx.size()){
				ans[t[node].idx[i]] = 1;
			}
		}
	}
	for(int i = 1 ; i <= q ; ++i)
		cout << ans[i] << endl;
}
