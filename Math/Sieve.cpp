//Generating prime numbers from 1 to n

const int MSIZE = 1000000;
bool isprime[MSIZE];
vector<int> primes;

void sieve(int n){
	fill(isprime, isprime+MSIZE, true);
	for(int i = 2; i <= n; i++){
		if(isprime[i]){
			for(int j = i*i; j <= n; j+= i){
				isprime[j] = false;
			}
		}
	}

	for(int i = 2; i <= n; i++){
		if(isprime[i]){
			primes.push_back(i);
		}
	}
}

void solve(int n){
	sieve(n);
}
