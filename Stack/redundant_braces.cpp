// https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    stack<char> s;
    int len = A.size();
    int i = -1, count;
    while(++i < len){
        if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            s.push(A[i]);
        else if(A[i] == ')'){
            count = 0;
            while(s.top() != '('){
                s.pop();
                count++;
            }
            if(count)
                s.pop();
            else
                return 1;
        }
    }
    return 0;
}
