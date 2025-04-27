class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head; // \U0001f440 No swap needed

        ListNode* temp = head;
        while (temp && temp->next) {
            // \U0001f501 Swap the values of two nodes
            int data = temp->val;
            temp->val = temp->next->val;
            temp->next->val = data;
            temp = temp->next->next; // Move to next pair \U0001f3c3‍♂️\U0001f3c3‍♀️
        }
        return head;
    }
};