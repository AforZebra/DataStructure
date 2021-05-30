// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string A) {
    queue<int>q;
    int len = A.size();
    vector<int>v(26,0);
    if(len < 2)
        return A;
    string res= "";
    res += A[0];
    q.push(A[0]);
    v[A[0]-'a']++;
    for(int i = 1;i < len;i++){
        v[A[i]-'a']++;
        if(v[A[i]-'a'] == 1)
            q.push(A[i]);
        while(!q.empty() && v[q.front()-'a'] != 1)
            q.pop();
        res += q.empty() ? '#' : q.front();
    }
    return res;
}
