// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v(n+1);
        v[0] = 1;
        for(int i = 1;i <= n;i++){
            v[i] = v[i-1]*(i);
        }
        k = k-1;
        string str = "";
        vector<int>num;
        for(int i = 1;i <= n;i++){
            num.push_back(i);
        }
        for(int i = 0, j = n;i < n;i++){
            str += to_string(num[k/v[j-1]]);
            num.erase(num.begin() + k/v[j-1]);
            k = k%v[j-1];
            j--;
        }
        return str;
    }
};
