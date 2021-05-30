// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    int len = A.size(), count;
    if(len < 2)
        return A[0];
    vector<int>leftMax(len, 0), rightMax(len, 0);
    stack<int>s;
    s.push(0);
    for(int i = 1; i < len;i++){
        count = 0;
        while(!s.empty() && A[i] <= A[s.top()]){
            count++;
            count += leftMax[s.top()];
            s.pop();
        }
        leftMax[i] = count;
        s.push(i);
    }
    while(!s.empty())s.pop();
    s.push(len-1);
    for(int i = len-2; i >= 0;i--){
        count = 0;
        while(!s.empty() && A[i] <= A[s.top()]){
            count++;
            count += rightMax[s.top()];
            s.pop();
        }
        rightMax[i] = count;
        s.push(i);
    }
    int res = 0;
    for(int i = 0; i < len;i++){
        res = max(res, (rightMax[i] + leftMax[i] + 1)*A[i]);
    }
    return res;
}
