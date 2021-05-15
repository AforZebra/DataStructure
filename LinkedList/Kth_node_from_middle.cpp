// https://www.interviewbit.com/problems/kth-node-from-middle/

int Solution::solve(ListNode* A, int B) {
    ListNode *loop = A, *curr;
    int length = 0, fromStart;
    
    while(loop != NULL){
        length++;
        loop = loop->next;
    }
    fromStart = length/2 - B;
    if(fromStart < 0)
        return -1;
        
    for(int i =0;i <= fromStart;i++){
        curr = A;
        A = A->next;
    }
    return curr->val;
}
