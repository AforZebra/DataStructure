// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0)return 0;
    int ans = 1, n = A.size();
    for(int i = 1, j = 1;i < n;i++){
        if(A[i] == A[i-1])continue;
        else{
            A[j] = A[i];
            j++;
            ans++;
        }
    }
    return ans;
}
