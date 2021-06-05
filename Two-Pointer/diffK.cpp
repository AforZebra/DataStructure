// https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    int len = A.size();
    for(int i = 0, j = i+1;i < len && j < len;){
        int diff = abs(A[i] - A[j]);
        if(diff == abs(B) && i != j)
            return 1;
        else if(diff > abs(B))i++;
        else j++;
    }
    return 0;
}
