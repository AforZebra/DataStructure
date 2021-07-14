// https://www.interviewbit.com/old/problems/generate-all-parentheses-ii/

void call(int open, int close, int A, vector<string>&ans, string &str){
    if(close >= A){
        ans.push_back(str);
        return;
    }
    int temp = str.size();
    if(open < A){
        str += "(";
        call(open+1, close, A, ans, str);
        str.pop_back();
    }
    if(close < open){
        str += ")";
        call(open, close+1, A, ans, str);
        str.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int A) {
    string str = "";
    vector<string>ans;
    call(0, 0, A, ans, str);
    return ans;
}
