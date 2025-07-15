class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (true) {
            
            ListNode* check = curr;
            for (int i = 0; i < k; i++) {
                if (!check) return dummy.next;
                check = check->next;
            }

            
            ListNode* last = prev->next;
            ListNode* next = nullptr;
            for (int i = 1; i < k; i++) {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }

            prev = last;
            curr = prev->next;
        }

        return dummy.next;
    }
};
