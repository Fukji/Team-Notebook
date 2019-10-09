//Finding the number of prime in the range of 1-n that is coprime to n

long long euler(long long n){
	double ans = n;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
			}
			ans *= (1.0 - (1.0/double(i)));
		}
	}

	if(n > 1)
		ans *= (1.0 - (1.0/(double)n));
	return (long long)ans;
}

void solve(long long n){
	long long ans = euler(n);
}
