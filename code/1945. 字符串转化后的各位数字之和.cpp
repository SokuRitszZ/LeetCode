class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - 'a' + 1;
            while (num) {
                res += num % 10;
                num /= 10;
            }
        }
        while (--k) {
            int nres = 0;
            while (res) {
                nres += res % 10;
                res /= 10;
            }
            res = nres;
        }
        return res;
    }
};