// interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int len = A.size(), diff = INT_MAX, ans, temp, i , j;
    for(int k = 0; k < len-1;k++){
        i = k+1, j = len-1;
        while(i < j){
            temp = A[i]+A[j]+A[k];
            if(diff > abs(B-temp)){
                diff = abs(B-temp);
                ans = temp;
            }
            if(temp < B)i++;
            else if(temp == B && i != j)return ans;
            else j--;
        }
    }
    return ans;
}
