// https://www.interviewbit.com/problems/balanced-parantheses/

int Solution::solve(string A) {
    int len = A.length(), i = 0, result = 0;
    while(i < len && result >= 0){
        if(A[i] == '(')
            result += 1;
        else
            result -= 1;
        i++;
    }
    if(!result)
        return 1;
    return 0;
}
