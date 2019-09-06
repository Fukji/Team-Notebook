#include <bits/stdc++.h>

using namespace std;

long long n;

long long cat(long long n) {
	long long ret=1;
	for(long long i=0;i<n;i++) {
		ret=ret*(2*n-i);
		ret=ret/(i+1);
	}
	ret=ret/(n+1);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	cout<<cat(n)<<endl;
}


