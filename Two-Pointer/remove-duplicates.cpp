// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int num, ans = 0;
        for(int i= 0;i < len;i++){
            num = nums[i];
            while(i < len && num == nums[i])
                i++;
            i--;
            nums[ans++] = num;
        }
        return ans;
    }
};
