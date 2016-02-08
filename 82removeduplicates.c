/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *ptr = head;
    while(ptr->next != NULL)
    {
        if(ptr->val == ptr->next->val)
        {
            if(ptr->next->next != NULL)
            {
                if(ptr == head)
                    head = ptr->next->next;
                else
                    ptr->next = ptr->next->next;
            }
            else
            {
                if(ptr == head)
                    head->next = NULL;
                else
                    ptr->next = NULL;
            }

            ptr = ptr->next;
        }
        else
            ptr = ptr->next;
    }
    return head;
}
