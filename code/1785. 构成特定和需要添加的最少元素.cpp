class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        return ceil(1.0 * abs(1ll * goal - accumulate(nums.begin(), nums.end(), 0ll)) / limit);
    }
};