// https://www.interviewbit.com/old/problems/letter-phone/

void call(int n, int idx, string A, vector<string>&ans, string str, vector<vector<int>>v){
    if(idx >= n){
        ans.push_back(str);
        return;
    }
    for(int i = 0;i < v[A[idx]-'0'].size();i++){
        str += v[A[idx]-'0'][i];
        call(n, idx+1, A, ans, str, v);
        str.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<vector<int>>v(10);
    v[0] = {'0'};
    v[1] = {'1'};
    v[2] = {'a','b','c'};
    v[3] = {'d','e','f'};
    v[4] = {'g','h','i'};
    v[5] = {'j','k','l'};
    v[6] = {'m','n','o'};
    v[7] = {'p','q','r','s'};
    v[8] = {'t','u','v'};
    v[9] = {'w','x','y','z'};
    vector<string>ans;
    string s = "";
    call(A.size(), 0, A, ans, s, v);
    return ans;
}
