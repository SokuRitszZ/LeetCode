class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0, j = 0, k = 0;
        while (i < groups.size() && j < nums.size()) {
            if (groups[i][k] == nums[j]) ++k;
            if (k == groups[i].size()) ++i, k = 0;
            ++j;
        }       
        return i == groups.size() && j == nums.size();
    }
};