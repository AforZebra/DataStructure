// https://www.interviewbit.com/old/problems/palindrome-partitioning/

bool isPalindrome(string s){
    int j = s.size()-1,i = 0;
    while(i <= j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}

void call(string s, vector<string>v, vector<vector<string>>&ans){
    if(s.size() == 0){
        ans.push_back(v);
        return;
    }
    for(int i = 0; i < s.size();i++){
        string prefix = s.substr(0,i+1);
        string left = s.substr(i+1);
        if(isPalindrome(prefix)){
            v.push_back(prefix);
            call(left, v, ans);
            v.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<string>v;
    vector<vector<string>>ans;
    call(A, v, ans);
    return ans;
}
