using cd = complex<ld>;
const ld PI = acos(-(ld)1);

void fft(vector<cd> &v, bool inv = 0) {
    int n = v.size();
    for(int i = 1, j = 0; i < n; i++) {
        int bt = n >> 1;
        for(; j&bt; bt >>= 1) j ^= bt;
        j ^= bt;
        if(i < j) swap(v[i], v[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i+=len) {
            cd w(1);
            for(int j = 0; j < len/2; j++) {
                cd uu = v[i+j], vv = v[i+j+len/2] * w;
                v[i+j] = uu+vv; v[i+j+len/2] = uu-vv;
                w *= wlen;
            }
        }
    }
    if(inv) for(cd &i : v) i /= n;
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa); fft(fb);
    for(int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, 1);
    vector<ll> res(n);
    for(int i = 0; i < n; i++) res[i] = round(fa[i].real());
    return res;
}
