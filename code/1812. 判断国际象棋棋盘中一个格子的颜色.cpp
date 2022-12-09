class Solution {
public:
    bool squareIsWhite(string coordinates) {
        stringstream ss;
        ss << coordinates;
        char c;
        int l;
        ss >> c >> l;
        return (l - 1 & 1) ^ (c - 'a' & 1);
    }
};