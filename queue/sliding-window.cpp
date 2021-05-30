// https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int len = A.size();
    if(B > len)
        B = len;
    deque<int>q;
    q.push_back(0);
    for(int i = 1;i < B;i++){
        while(!q.empty() && A[q.back()] < A[i])
            q.pop_back();
        q.push_back(i);
    }
    vector<int>c;
    c.push_back(A[q.front()]);
    for(int i = 1; i <= len - B;i++){
        if(q.front() < i)q.pop_front();
        while(!q.empty() && (A[q.back()] < A[i+B-1]))
            q.pop_back();
        q.push_back(i+B-1);
        c.push_back(A[q.front()]);
    }
    return c;
}
