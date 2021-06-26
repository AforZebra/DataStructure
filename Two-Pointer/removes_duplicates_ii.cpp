// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

int Solution::removeDuplicates(vector<int> &A) {
    int j = 1, sizeA = A.size(), repeat = 1;
    if(A.size() == 0)return 0;
    for(int i = 1;i < sizeA;i++){
        if(A[i] == A[i-1]){
            repeat++;
        }
        else
            repeat = 1;
        if(repeat > 2)continue;
        A[j] = A[i];
        j++;
    }
    return j;
}
