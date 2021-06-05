// https://www.interviewbit.com/problems/maximum-ones-after-modification/

int Solution::solve(vector<int> &A, int B) {
    int zeroCount = B, count = 0, ans = 0, i = 0, n = A.size(),j = 0;
    while(i < n){
        while(j < n){
            if(A[j] == 1)
                count++;
            else{
                if(zeroCount){
                    zeroCount--;
                    count++;
                }
                else
                    break;
            }
            j++;
        }
        ans = max(ans, count);
        while(i < n && A[i++] != 0)count--;
            zeroCount++;
            count--;
    }
    return ans;
}
