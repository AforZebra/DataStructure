// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    stack<string>s;
    int len = A.size(), first, second, temp;
    for(int i = 0;i < len;i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            second = stoi(s.top());s.pop();
            first = stoi(s.top());s.pop();
            if(A[i] == "+")
                temp = first + second;
            else if(A[i] == "-")
                temp = first - second;
            else if(A[i] == "*")
                temp = first * second;
            else if(A[i] == "/")
                temp = first / second;
            s.push(to_string(temp));
        }
        else
            s.push(A[i]);
    }
    return stoi(s.top());
}
