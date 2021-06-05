// https://www.interviewbit.com/problems/counting-triangles/

int Solution::nTriang(vector<int> &A) {
    long long ans = 0, len = A.size();
    sort(A.begin(), A.end());
    for(int i = len-1; i > 1; i--){
        for(int j = 0, k = i-1;j < k;){
            if(A[j] + A[k] > A[i]){
                ans += 0LL + k-j;
                k--;
            }
            else
                j++;
        }
    }
    return int(ans%1000000007);
}
