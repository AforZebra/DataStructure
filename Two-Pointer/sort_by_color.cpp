// https://www.interviewbit.com/problems/sort-by-color/

void Solution::sortColors(vector<int> &A) {
    int z = 0, o = 0, t = 0, sizeA = A.size();
    for(int i = 0;i < sizeA;i++){
        if(A[i] == 1)o++;
        else if(A[i] == 2)t++;
        else z++;
    }
    int i = 0;
    while(z--){
        A[i++] = 0;
    }
    while(o--){
        A[i++] = 1;
    }
    while(t--){
        A[i++] = 2;
    }
}
