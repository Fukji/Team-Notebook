//Generating prime numbers from 1 to n, counting numbers from 1..n coprime to n, finding the sum of the divisors of n

const long long MAXN = 10000005;
long long SPF[MAXN+10], M[MAXN + 10];
bool B[MAXN];
vector<long long> prima;

void sieveAndMobius() {
	prima.clear(); memset(B,true,sizeof(B)); B[0]=B[1]=false; 
	for (long long i=2;i<MAXN;i++) { 
	    if (B[i]) prima.push_back(i), SPF[i]=i; 
	    for (long long j=0;j<prima.size() && i*prima[j]<MAXN && prima[j]<=SPF[i];j++) 
		B[i*prima[j]]=false, SPF[i*prima[j]]=prima[j];
	} 
	for (long long i=1;i<MAXN;i++) { 
	    if (i==1) M[i]=1; else if (SPF[i]==i) M[i]=-1; 
	    else if ((i/SPF[i])%SPF[i]==0) M[i]=0; else M[i]=M[i/SPF[i]]*M[SPF[i]];
	} 
}

int phi(int n) {
    int result = n;
    for(int p = 2; p * p <= n; ++p) {
         
        // Check if p is a prime factor.
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

long long sumdiv(long long n){
	long long ans = 1;
	long long prime, idx = 0;
	while(primes[idx] * primes[idx] <= n){
		long long power = 0;
		prime = primes[idx];
		while(n % prime == 0){
			n /= prime;
			power++;
		}
		ans *= ((long long)pow((double)prime, power+1.0)-1) / (prime-1);
		idx++;
	}
	if(n != 1){
		ans *= ((long long)pow((double)n, 2.0)) / (n-1);
	}
	return ans;
}

void solve(int n){
	sieve(n);

	//count of numbers from 1..n coprime to n
	long long totatives = eulerphi(n);
	
	//sum of divisors of n
	long long sum = sumdiv(n);
}
