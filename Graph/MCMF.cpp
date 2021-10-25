#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);(a)++)
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);(a)--)
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);(a)--)
#define FOR(a, b) for(auto (a) : b)


class MCMF {
	public:
		const int INF = 1000000000;
		static const int SZ = 3005;

		int cap[SZ][SZ];
		int cost[SZ][SZ];
		int SRC, SINK;
		int par[SZ];
		vector<vector<int> > adj = vector<vector<int> > (SZ, vector<int>());
		vector<int> d;
		vector<int> p;
		int flow = 0, costPerFlow= 0;

		bool spfa(vector<int>& d, vector<int> &p)
		{
			int n = adj.size();
			d = vector<int>(n + 1, INF);
			p = vector<int>(n + 1, 0);
			vector<int> cnt(n + 1, 0);
			vector<bool> in(n + 1, false);
			queue<int> q;

			d[SRC] = 0;
			q.push(SRC);
			in[SRC] = true;

			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				in[u] = false;

				for (auto edge : adj[u])
				{
					int to = edge;
					int len = cost[u][to];

					if (d[u] + len < d[to] && cap[u][to] > 0)
					{
						d[to] = d[u] + len;
						p[to] = u;

						if (!in[to])
						{
							q.push(to);
							in[to] = true;
							
							cnt[to]++;
							if (cnt[to] > n) return false;
						}
					}
				}
			}

			return d[SINK] != INF;
		}

		void augment(int u, int minEdge)
		{
			if (u == SRC) { flow = minEdge; return; }
			else if (p[u] != -1)
			{
				augment(p[u], min(minEdge, cap[p[u]][u]));
				cap[p[u]][u] -= flow;
				cap[u][p[u]] += flow;
				costPerFlow += cost[p[u]][u];
			}
		}

		pair<int, int> solve(int K = 1e9)
		{
			int totalCost = 0, maxFlow = 0;
			while (spfa(d, p))
			{
				flow = 0; costPerFlow = 0;
				augment(SINK, INF);
				totalCost += costPerFlow;
				maxFlow += flow;
			}
			return {maxFlow, totalCost};
		}

		void addEdge(int u, int v, int val, int c = 1)
		{
			adj[u].push_back(v);
			adj[v].push_back(u);
			cost[u][v] = val;
			cost[v][u] = -val;
			cap[u][v] = c;
			cap[v][u] = 0;
		}

		void resetEdge()
		{
			for(int i = 0 ; i < SZ ; i++)
			{
				adj[i].clear();
			}
		}

		MCMF(){

		}
};
