// https://www.interviewbit.com/old/problems/gray-code/

int find(string s){
    int value = 0;
    int indexCounter = 0;
    for(int i=s.length()-1;i>=0;i--){
    
        if(s[i]=='1'){
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}

void call(int n, unordered_set<string>&us, string s, vector<int>&ans){
    if(us.find(s) == us.end()){
        ans.push_back(find(s));
        us.insert(s);
    }
    else return;
    if(ans.size() >= pow(2,n))return;
    for(int i = n-1;i >= 0;i--){
        s[i] = (s[i] == '1') ? '0' : '1';
        call(n, us, s, ans);
        s[i] = (s[i] == '1') ? '0' : '1';
    }
}

vector<int> Solution::grayCode(int A) {
    string s = "";
    vector<int>ans;
    for(int i = 0;i < A;i++){
        s += '0';
    }
    unordered_set<string>us;
    call(A, us, s, ans);
    return ans;
}
