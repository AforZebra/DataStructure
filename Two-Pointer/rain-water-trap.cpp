// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    int len = A.size();
    int left = 0, right = len-1, rightMx = INT_MIN, leftMx = INT_MIN, res = 0;
    while(left <= right){
        if(A[left] < A[right]){
            if(A[left] > leftMx)leftMx = A[left];
            else res += leftMx-A[left];
            left++;
        }
        else{
            if(A[right] > rightMx)rightMx = A[right];
            else res += rightMx-A[right];
            right--;
        }
    }
    return res;
}
