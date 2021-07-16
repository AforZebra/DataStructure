// https://www.interviewbit.com/old/problems/sudoku/

bool isValid(int idxI, int idxJ, char c, vector<vector<char> > &A){
    for(int i = 0;i < 9;i++){
        if(A[i][idxJ] == c)return false;
    }
    for(int j = 0;j < 9;j++){
        if(A[idxI][j] == c)return false;
    }
    int x = (idxI/3) * 3;
    int y = (idxJ/3) * 3;
    for(int i = x;i < x+3;i++){
        for(int j = y;j < y+3;j++){
            if(A[i][j] == c)return false;
        }
    }
    return true;
}

bool call(vector<vector<char> > &A){
    for(int i = 0;i < 9;i++){
        for(int j  = 0;j < 9;j++){
            if(A[i][j] == '.'){
                for(char c = '1'; c <= '9';c++){
                    if(isValid(i,j,c,A)){
                        A[i][j] = c;
                        if(call(A))
                            return true;
                        A[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    call(A);
}
