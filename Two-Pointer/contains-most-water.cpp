// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(), left = 0, right = len-1, ans = 0, prod;
        while(left <= right){
            if(height[left] < height[right]){
                prod = height[left]*(right-left);
                left++;
            }
            else{
                prod = height[right]*(right-left);
                right--;
            }
            ans = max(ans, prod);
        }
        return ans;
    }
};
