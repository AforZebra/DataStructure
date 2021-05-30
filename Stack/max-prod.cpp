// https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) {
    int len = A.size();
    stack<int>s;
    vector<int>leftMax(len, 0);
    vector<int>rightMax(len, 0);
    s.push(0);
    leftMax[0] = 0;
    for(int i =1;i < len;i++){
        while(!s.empty()){
            if(A[i]<A[s.top()])break;
            s.pop();
        }
        leftMax[i] = (s.empty())?0:s.top();
        s.push(i);
    }
    stack<int>a;
    a.push(len-1);
    rightMax[len-1]=0;
    for(int i = len-2;i >= 0;i--){
        while(!a.empty()){
            if(A[i]<A[a.top()])break;
            a.pop();
        }
        rightMax[i] = (a.empty())?0:a.top();
        a.push(i);
    }
    
    long long result = -1;
    for(int i = 0;i < len;i++){
        result = max(result, rightMax[i] * leftMax[i]*1LL);
    }
    return result%1000000007;
}
