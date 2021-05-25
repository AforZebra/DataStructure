// https://www.interviewbit.com/problems/list-cycle/

ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    ListNode *prev = NULL, *next;
    while(A && A != temp){
        next = A->next;
        A->next = temp;
        prev = A;
        A = next;
    }
    if(A == NULL)
        return NULL;
    return prev;
}
