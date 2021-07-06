// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

class Solution {

public:
    void calXor(vector<int>nums, int &sum, int xr, int idx, int n){
        sum += xr;
        for(int i = idx;i < n;i++){
            calXor(nums, sum, xr^nums[i],i+1, n);
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        calXor(nums, sum, 0, 0, n);
        return sum;
    }
};
