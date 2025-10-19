// LeetCode 206: Reverse Linked List
// Solution using an iterative approach with 3 pointers
// Time Complexity: O(n)

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nextTemp = nullptr;
        
        while (current != nullptr) {
            // 1. Store the next node
            nextTemp = current->next;
            
            // 2. Reverse the current node's pointer
            current->next = prev;
            
            // 3. Move pointers one step forward
            prev = current;
            current = nextTemp;
        }
        
        // 'prev' will be the new head at the end
        return prev;
    }
};

// Helper function to create a list (for testing)
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a list (for testing)
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Main function to test the code
int main() {
    Solution sol;
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = sol.reverseList(head);
    
    cout << "Reversed list: ";
    printList(reversedHead);
    
    return 0;
}
