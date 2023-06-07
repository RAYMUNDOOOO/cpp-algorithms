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

/*
 * Create a two pointers, one for the newly head of the merged list, and another for the tail
 * that will keep track of the newly merged list;
 *
 * You will notice that tail is pointing to the same memory address as merged_head, but don't be fooled
 * as this is only for the first iteration of the while loop where we figure out what the head of this new 
 * linked list is.
 *
 * After that, we just get the tail's next to point to either list 1 or list 2, setting the pointer for list1 and 
 * list2 to their respective "next" pointers with each iteration.
 *
 * Once we're finished, we can attach the tail to either list that still has remaining nodes because they're already sorted,
 * so we can assume that the list will stay sorted.
 *
 * Then we can return merged_head->next because in the first iteration of the loop, where we did:
 * tail->next = listx, we were essentially saying, merged_head->next = listx;
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged_head = new ListNode(-1);
        ListNode* tail = merged_head;

        while (list1 && list2) {
           // The first iteration of this while loop will set where merged_head->next points to 
           if (list1->val < list2->val) {
               tail->next = list1;
               list1 = list1->next;
           } else {
               tail->next = list2;
               list2 = list2->next;
           }

           tail = tail->next;
        }

        if (!list1) tail->next = list2;
        if (!list2) tail->next = list1;

        return merged_head->next;
    }   
};
    
