// https://www.interviewbit.com/problems/pair-with-given-difference/

int Solution::solve(vector<int> &A, int B) {
    unordered_set<int>s;
    int len = A.size();
    for(int i = 0;i < len;i++){
        if(!s.empty()){
            if(s.find(A[i]+B) != s.end() || s.find(A[i]-B) != s.end())
                return 1;
        }
        s.insert(A[i]);
    }
    return 0;
}
