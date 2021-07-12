// https://www.interviewbit.com/old/problems/subsets-ii/

void call(int idx, vector<int>A, int n, vector<vector<int>> &result, vector<int>v, string s, unordered_set<string>&us){
    if(us.find(s) == us.end()){
        us.insert(s);
        result.push_back(v);
    }
    else return;
    for(int i = idx;i < n;i++){
        v.push_back(A[i]);
        int strSize = s.size();
        s += to_string(A[i]);
        call(i+1, A, n, result, v, s, us);
        s = s.substr(0,strSize);
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int> > result;
    vector<int>v;
    unordered_set<string>us;
    sort(A.begin(),A.end());
    call(0, A, A.size(), result, v, "", us);
    return result;
}


// Updated

void call(int idx, vector<int>A, int n, vector<vector<int>> &result, vector<int>v){
    result.push_back(v);
    for(int i = idx;i < n;i++){
        v.push_back(A[i]);
        call(i+1, A, n, result, v);
        while(i < n-1 && A[i] == A[i+1])
            i++;
        v.pop_back();
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<int>v;
    vector<vector<int> > result;
    sort(A.begin(),A.end());
    call(0, A, A.size(), result, v);
    return result;
}
