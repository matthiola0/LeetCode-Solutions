class Fancy {
private:
    vector<int> x;
    int add, mult;
    int mod = 1e9 + 7;

    int qpow(int mul, int t) {
        if (t == 1) return mul;
        if (t == 0) return 1;
        int res = qpow(1LL * mul * mul % mod, t / 2);
        if (t % 2) {
            res = 1LL * res * mul % mod;
        }
        return res;
    }
public:
    Fancy() {
        add = 0;
        mult = 1;
    }
    
    void append(int val) {
        val = ((val - add) % mod + mod) % mod;;
        val = (1LL * val * qpow(mult, mod - 2)) % mod;
        x.push_back(val);
    }
    
    void addAll(int inc) {
        add = (0LL + add + inc) % mod;
    }
    
    void multAll(int m) {
        add = (1LL * add * m) % mod;
        mult = (1LL * mult * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= x.size()) return -1;
        return (1LL * x[idx] * mult + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */