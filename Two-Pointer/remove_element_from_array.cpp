// https://www.interviewbit.com/problems/remove-element-from-array/

int Solution::removeElement(vector<int> &A, int B) {
    int sizeA = A.size();
    int j = 0;
    for(int i =0;i < sizeA;i++){
        if(A[i] != B)A[j++] = A[i];
    }
    return j;
}
