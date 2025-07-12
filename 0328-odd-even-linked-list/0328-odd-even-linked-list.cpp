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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return nullptr;

        ListNode* oddstart = nullptr,*oddend = nullptr,*evenstart = nullptr,*evenend = nullptr;

        ListNode* curr = head;
        int pos =1;
        while(curr){
            if(pos%2!=0){
                if(oddstart == nullptr){
                    oddstart = oddend = curr;
                }
                else{
                    oddend->next = curr;
                    oddend = curr;
                }
            }
            else{
                if(evenstart == nullptr){
                    evenstart = evenend = curr;
                }
                else{
                    evenend->next = curr;
                    evenend = curr;
                }
            }
            curr=curr->next;
            pos++;
        }
        if(oddend!=nullptr){
            oddend->next = evenstart;
        }
        if(evenend!=nullptr){
            evenend->next = nullptr;
        }

        return (oddstart!=nullptr) ?oddstart : evenstart;
    }
};