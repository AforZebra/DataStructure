// https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/994/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root)q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node *temp = NULL;
            while(size--){
                if(q.front()->right)q.push(q.front()->right);
                if(q.front()->left)q.push(q.front()->left);
                q.front()->next = temp;
                temp = q.front();
                q.pop();
            }
        }
        return root;
    }
};
