/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *ptr1 = NULL, *ptr2 = NULL, *prev = NULL;
    if(head == NULL || head->next == NULL)
      return head;
    else
    {
      ptr1 = head;
      head = ptr1->next;
      ptr2 = head->next;
      head->next = ptr1;
      ptr1->next = ptr2;
      while(ptr2 != NULL && ptr2->next != NULL)
      {
        prev = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr1->next->next;
        prev->next = ptr1->next;
        ptr1->next->next = ptr1;
        ptr1->next = ptr2;
      }
    }
    return head;
}
