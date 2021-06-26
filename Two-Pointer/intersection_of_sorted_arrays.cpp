// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int sizeA = A.size(), sizeB = B.size();
    unordered_multiset<int>s;
    vector<int>ans;
    for(int i = 0;i < sizeA;i++){
        s.insert(A[i]);
    }
    for(int j = 0;j < sizeB;j++){
        if(s.find(B[j]) != s.end()){
            ans.push_back(B[j]);
            s.erase(s.find(B[j]));
        }
    }
    return ans;
}
