// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int sizeA = A.size(), sizeB = B.size(), i = sizeA - 1, j = sizeB -1, k = sizeA + sizeB -1;
    A.resize(sizeA + sizeB);
    while(k >= 0){
        if(i == -1)A[k--] = B[j--];
        else if(j == -1)A[k--] = A[i--];
        else{
            if(A[i] > B[j])A[k--] = A[i--];
            else A[k--] = B[j--];
        }
    }
}
