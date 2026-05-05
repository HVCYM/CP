#include<bits/stdc++.h>
using namespace std;

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
  ListNode* rotateRight(ListNode* head, int k) {
    int n = 0;
    auto backup = head;
    auto tail = new ListNode();
    while(head != nullptr) {
      if (head -> next == nullptr) {
        tail = head;
      }
      head = head -> next;
      n += 1;
    }
    if (n == 0) {
      return head;
    }
    head = backup;
    k = k % n;
    if (k == 0) {
      return head;
    }
    k = n - k;
    auto front = head;
    while(k--) {
      front = head;
      head = head -> next;
    }
    tail -> next = backup;
    front -> next = nullptr;
    return head;
  }
};
