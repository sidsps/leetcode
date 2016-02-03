/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ptr1 = l1, *ptr2 = l2, *merged = NULL, *ptr = NULL, *smaller;
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    else if(l1 == NULL && l2 == NULL)
        return merged;
    else
    {
        smaller = (ptr1->val < ptr2->val) ? ptr1 : ptr2;
        if(merged == NULL)
        {
            merged = smaller;
            ptr = merged;
            if(smaller == ptr1)
                ptr1 = ptr1->next;
            else
                ptr2 = ptr2->next;
        }
        while(ptr1 != NULL && ptr2 != NULL)
        {
            smaller = (ptr1->val < ptr2->val) ? ptr1 : ptr2;
            ptr->next = smaller;
            if(smaller == ptr1)
                ptr1 = ptr1->next;
            else
                ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        if(ptr1 == NULL)
            smaller->next = ptr2;
        else
            smaller->next = ptr1;
    }
    return merged;
}
