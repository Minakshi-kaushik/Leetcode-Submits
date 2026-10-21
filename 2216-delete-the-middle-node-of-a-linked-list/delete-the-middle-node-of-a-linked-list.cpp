/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        //if only one node exists
        if(head == NULL || head->next == NULL) return NULL;

        // finding the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
         while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
         }
        //deletion of the node
        prev->next = slow->next;
        delete slow;
        return head;
    }
};