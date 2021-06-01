// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    int len = A.size(), mx = INT_MIN;
    vector<int>left(len, 0), right(len, 0);
    for(int i = 0;i < len;i++){
        mx = max(mx, A[i]);
        left[i] = max(0, mx-A[i]);
    }
    mx = INT_MIN;
    for(int i = len-1;i >= 0;i--){
        mx = max(mx, A[i]);
        right[i] = max(0, mx-A[i]);
    }
    int res = 0;
    for(int i = 0;i < len;i++){
        res += min(left[i], right[i]);
    }
    return res;
}
