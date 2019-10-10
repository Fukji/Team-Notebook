//Finding the convex hull of a set of points
//Requires: 1D.cpp

const double EPS = 0.0000001;
vector<point> pts;

vector<point> convexhull(){
	int n = pts.size();
	int k = 0;

	if(n <= 3){
		return pts;
	}

	vector<point> ans(2*n);

	sort(pts.begin(), pts.end());
	
	for(int i = 0; i < n; i++){
		while(k >= 2 && ccw(ans[k-2], ans[k-1], pts[i]) <= EPS){
			k--;
		}
		ans[k++] = pts[i];
	}
	
	for(int i = n-1, t = k+1; i > 0; i--){
		while(k >= t && ccw(ans[k-2], ans[k-1], pts[i-1]) <= EPS){
			k--;
		}
		ans[k++] = pts[i-1];
	}
	
	ans.resize(k-1);
	return ans;
}


void solve(){
	vector<point> ans = convexhull();
}
