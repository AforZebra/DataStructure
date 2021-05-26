// https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    int len = A.size(), i = 0;
    vector<string> s;
    string temp;
    while(i < len){
        temp = "";
        if(isalnum(A[i])){
            while(i < len && isalnum(A[i])){
                temp += A[i];
                i++;
            }
            s.push_back(temp);
        }
        else if(A[i] =='.'){
            if((i+1 < len) && (A[i+1] == '.')){
                i++;
                if(!s.empty())
                    s.pop_back();
            }
        }
        i++;
    }
    string result = "";
    int vecLen = s.size();
    i = 0;
    if(vecLen){
        while(i < vecLen){
            result += "/" + s[i];
            i++;
        }
        return result;
    }
    return "/";
}
