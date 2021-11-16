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
