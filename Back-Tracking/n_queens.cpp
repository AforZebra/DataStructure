// https://www.interviewbit.com/old/problems/nqueens/

void blockWays(int idxI, int idxJ, int n, vector<string> &vstr){
    for(int i = idxI;i < n;i++){
        vstr[i][idxJ] = '.';
    }
    for(int j = idxJ;j < n;j++){
        vstr[idxI][j] = '.';
    }
    for(int i = idxI, j = idxJ; i <n&&j<n;){
        vstr[i++][j++] = '.';
    }
    for(int i = idxI, j = idxJ; i < n&&j>=0;){
        vstr[i++][j--] = '.';
    }
}

void solve(int idx, int n, vector<string>vstr, vector<vector<string>>&ans){
    if(idx >= n){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
            if(vstr[i][j] == '0')vstr[i][j]='.';
        }
        ans.push_back(vstr);
        return;
    }
    for(int j = 0;j < n;j++){
        if(vstr[idx][j] != '.'){
            vector<string>temp = vstr;
            blockWays(idx, j, n, vstr);
            vstr[idx][j] = 'Q';
            solve(idx+1, n, vstr, ans);
            vstr = temp;
        }
    }
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<string>vstr;
    vector<vector<string>>ans;
    string str = "";
    for(int i = 0;i < A;i++)
        str += '0';
    for(int i = 0;i < A;i++)
        vstr.push_back(str);
    solve(0, A, vstr, ans);
    return ans;
}


// updated

void blockWays(int idxI, int idxJ, int n, vector<string> &vstr){
    for(int i = idxI;i < n;i++){
        vstr[i][idxJ] = '.';
    }
    for(int j = idxJ;j < n;j++){
        vstr[idxI][j] = '.';
    }
    for(int i = idxI, j = idxJ; i <n&&j<n;){
        vstr[i++][j++] = '.';
    }
    for(int i = idxI, j = idxJ; i < n&&j>=0;){
        vstr[i++][j--] = '.';
    }
}

void solve(int idx, int n, vector<string>vstr, vector<vector<string>>&ans){
    if(idx >= n){
        ans.push_back(vstr);
        return;
    }
    for(int j = 0;j < n;j++){
        if(vstr[idx][j] != '.'){
            vector<string>temp = vstr;
            blockWays(idx, j, n, vstr);
            vstr[idx][j] = 'Q';
            solve(idx+1, n, vstr, ans);
            vstr = temp;
            vstr[idx][j] = '.';
        }
    }
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<string>vstr;
    vector<vector<string>>ans;
    string str = "";
    for(int i = 0;i < A;i++)
        str += '0';
    for(int i = 0;i < A;i++)
        vstr.push_back(str);
    solve(0, A, vstr, ans);
    return ans;
}

