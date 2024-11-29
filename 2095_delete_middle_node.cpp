class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            // If there's only one node, return nullptr
            return nullptr;
        }
        
        // Correctly count the number of nodes
        int nodeCount = 1;
        ListNode* copy = head;
        while (copy->next != nullptr){
            nodeCount++;
            copy = copy->next;
        }
        
        int middle = nodeCount / 2;  // Correct middle index calculation
        
        // Traverse to the node before the middle node
        copy = head;
        for (int i = 0; i < middle - 1; i++){
            copy = copy->next;
        }
        
        // Remove the middle node by adjusting pointers
        copy->next = copy->next->next;
        
        return head;  // Return the original head
    }
};

