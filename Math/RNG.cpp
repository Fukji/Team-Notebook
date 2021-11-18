	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int ret = (uniform_real_distribution<long double>(0,1)(rng));
	return ret;
