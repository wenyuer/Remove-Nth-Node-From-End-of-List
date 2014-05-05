/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL || n<=0)
            return NULL;
        ListNode *p1 = head;
        
        for(int i=0; i<n-1; i++)     //note: let p1 run n-1 steps! not n steps!
        {
            if(p1->next != NULL)
                p1 = p1->next;
            else
             return NULL;
        }

        ListNode *p2 = head; 
        ListNode *p3 = NULL;
        while(p1->next!=NULL)
        {
            p3 = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        if(p2 == head)
        {
            head = p2->next;
            delete p2;
        }
        else
        {
            p3->next = p2->next;
            delete p2;
        }
        
        return head;
    }
};