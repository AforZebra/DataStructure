// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *loop = A, *startNode = A, *prev, *prevStartNode = NULL, *head = A;
    while(loop != NULL){
        int counter = 0;
        while((loop != NULL) && (loop->val == startNode->val)){
            prev = loop;
            loop = loop->next;
            counter++;
        }
        if(counter > 1)
            if(prevStartNode == NULL)
                head = loop;
            else
                prevStartNode->next = loop;
        else
            prevStartNode = prev;
        startNode = loop;
    }
    return head;
}
