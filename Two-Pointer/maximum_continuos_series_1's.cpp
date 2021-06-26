// https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> Solution::maxone(vector<int> &A, int B) {
    vector<int>v;
    int diff = INT_MIN, maxi = 0, maxj = 0, n = A.size();
    for(int i = 0, j = 0;i < n;i++){
        if(A[i] == 0)B--;
        while(B == -1){
            if(A[j] == 0)B++;
            j++;
        }
        if(diff < i-j+1){
            diff = i-j+1;
            maxi = i;
            maxj = j;
        }
    }
    for(int j = maxj; j <= maxi;j++)
        v.push_back(j);
    return v;
}
