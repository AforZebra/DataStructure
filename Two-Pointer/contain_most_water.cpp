// https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {
    int ans = 0, l = 0, r = A.size()-1;
    while(l < r){
        if(A[l] < A[r]){
            ans = max(ans, (r-l)*A[l]);
            l++;
        }
        else{
            ans = max(ans, (r-l)*A[r]);
            r--;
        }
    }
    return ans;
}
