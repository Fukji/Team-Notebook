#include <iostream>
#include <vector>
using namespace std;

class ufds{
private:
	vector<int> rank, p, sizes;
	int numsets;

public:
	ufds(int n){
		rank.assign(n, 0);
		sizes.assign(n, 1);
		p.assign(n, 0);
		numsets = n;
		for(int i = 0; i < n; i++){
			p[i] = i;
		}
	}
	int findset(int i){
		if(p[i] == i){
			return i;
		}
		return p[i] = findset(p[i]);
	}
	bool sameset(int i, int j){
		return findset(i) == findset(j);
	}
	void unionset(int i, int j){
		if(!sameset(i, j)){
			numsets--;
			int p1 = findset(i);
			int p2 = findset(j);
			if(rank[p1] > rank[p2]){
				sizes[p1] += sizes[p2];
				p[p2] = p1;
			}
			else{
				sizes[p2] += sizes[p1];
				p[p1] = p2;
				if(rank[p1] == rank[p2]){
					rank[p2]++;
				}
			}
		}
	}
	int countsizes(int i){
		return sizes[findset(i)];
	}
	int countnum(){
		return numsets;
	}
};
