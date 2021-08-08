// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int count = 0;
        stack<pair<Node*,int>>s1,s2;
        if(!root1 || !root2)return 0;
        s1.push({root1,0});
        s2.push({root2,0});
        while(!s1.empty() && !s2.empty()){
            pair<Node*, int> top1 = s1.top(), top2 = s2.top();
            if(top1.first->left != NULL && top1.second == 0){
                s1.top().second = top1.second + 1;
                s1.push({top1.first->left,0});
            }
            else if(top2.first->right != NULL && top2.second == 0){
                s2.top().second = top2.second + 1;
                s2.push({top2.first->right,0});
            }
            else{
                if(top1.first->data + top2.first->data == x){
                    s1.pop();
                    s2.pop();
                    count++;
                    if(top1.first->right != NULL)
                        s1.push({top1.first->right,0});
                    if(top2.first->left != NULL)
                        s2.push({top2.first->left,0});
                }
                else if(top1.first->data + top2.first->data > x){
                    s2.pop();
                    if(top2.first->left != NULL)
                        s2.push({top2.first->left,0});
                }
                else{
                    s1.pop();
                    if(top1.first->right != NULL)
                        s1.push({top1.first->right,0});
                }
            }
        }
        return count;
    }
};
