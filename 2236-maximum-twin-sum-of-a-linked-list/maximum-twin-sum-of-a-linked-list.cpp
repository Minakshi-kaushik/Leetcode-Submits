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

    int sizeLL(ListNode* head){
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        return size;
    }
    vector<int> LLtoArr(ListNode* head){
        vector<int> result;
        ListNode* temp = head;
        int i = 0;
        while(temp){
            result.push_back(temp->val);
            i++;
            temp = temp->next;
        }
        return result;
    }
    int pairSum(ListNode* head) {
        int maxi = INT_MIN;
        ListNode* temp = head;
        int n = sizeLL(head);

        vector<int> result = LLtoArr(head);

        for(int i = 0; i <= (n/2)-1; i++){
            int sum = result[i] + result[n-1-i];
            maxi = max(sum, maxi); 

        }
        return maxi;
        
    }
};