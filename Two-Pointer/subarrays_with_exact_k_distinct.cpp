// https://www.interviewbit.com/old/problems/subarrays-with-distinct-integers/

int countSubArray(vector<int>A, int B){
    int n = A.size(), ans = 0;
    unordered_map<int, int>mp;
    for(int i = 0, j = 0;j < n;){
        mp[A[j]]++;
        while(mp.size() > B){
            mp[A[i]]--;
            if(mp[A[i]] == 0)
                mp.erase(A[i]);
            i++;
        }
        ans += j-i+1;
        j++;
    }
    return ans;
}


int Solution::solve(vector<int> &A, int B) {
    return countSubArray(A, B) - countSubArray(A, B-1);
}
