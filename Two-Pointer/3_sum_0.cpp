// https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    int len = A.size(), idx = 0, temp, b, c;
    vector<vector<int> > v;
    if(len < 3)return v;
    int j, k, sum;
    for(int i = 0;i < len-2;i++){
        if(A[i] > 0)break;
        if(i > 0 && A[i] == A[i-1])continue;
        j = i+1;
        k = len-1;
        while(j < k){
            sum = A[i] + A[j] + A[k];
            b = A[j];
            c = A[k];
            if(sum == 0){
                v.push_back({A[i], b, c});
                while(c == A[--k]);
                while(b == A[++j]);
            }
            else if(sum > 0)k--;
            else j++;
        }
    }
    return v;
}
