// https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), ans = 0, sum = 0;
    for(int i = 0, j = 0; i < n && j < n;){
        if(A[j] + sum < B){
            ans += 1 + j - i;
            sum += A[j++];
        }
        else{
            if(A[j] > B){
                i = ++j;
                sum = 0;
            }
            else{
                sum -= A[i++];
            }
        }
    }
    return ans;
}
