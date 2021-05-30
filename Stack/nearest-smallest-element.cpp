// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int len = A.size(), i = 0;
    vector<int> v(len, -1);
    if(len < 2)
        return v;
    stack<int>s;
    s.push(A[0]);
    while(++i < len){
        while(!s.empty() && A[i] <= s.top()){
            s.pop();
        }
        if(!s.empty())
            v[i]=s.top();
        s.push(A[i]);
    }
    return v;
}
