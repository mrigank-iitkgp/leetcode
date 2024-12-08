class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int resultIdx = i;
            if (nums[i] > 0) {
                resultIdx = (i + nums[i]) % n;
            } else if (nums[i] < 0) {
                resultIdx = n - (n - i - 1 + abs(nums[i])) % n - 1;
            }
            result[i] = nums[resultIdx];
        }
        return result;
    }
};
