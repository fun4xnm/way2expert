#ifndef LINKED_LIST_CYCLE_H_
#define LINKED_LIST_CYCLE_H_

#include "problem/list_node.h"

namespace problem {

// Given head, the head of a linked list, determine if the linked list has a
// cycle in it.

// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

bool HasCycle(ListNode* head) {
  if (!head) return false;

  ListNode* slow = head;
  ListNode* fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

}  // namespace problem

#endif