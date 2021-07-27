// https://www.interviewbit.com/old/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &A) {
    int sum = 0, ans = INT_MAX;
    for(auto i:A)sum += i;
    vector<bool>dp(sum+2,false);
    for(int i = 0;i < A.size();i++){
        for(int j = sum;j >= 0;j--){
            if(dp[j])dp[j+A[i]] = true;
        }
        dp[A[i]] = true;
    }
    for(int i = 0;i <= sum;i++){
        ans = min(ans, abs(sum-2*i));
    }
    return ans;
}
