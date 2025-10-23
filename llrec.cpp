#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  /*
    smaller is the pointer to the head of a new singly linked list containing
        all elements of head that were less than or equal to the pivot.

    larger is the pointer to the head of a new singly linked list containing
        all elements of head that were (strictly) larger than the pivot.

    the linked list head no longer exists (head should be set to NULL). 

    recursive function

    maintain ordering

    must run O(n)


  
  */

  if (head == nullptr) {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* finisher = head->next;
  head->next = nullptr;


    // if node should go to larger
    if (head->val > pivot) {
      larger = head;
      head = finisher;
      llpivot(head, smaller, larger->next, pivot);
      return;
    }

    // if node is less than or equal to therefore should go to smaller
    else {
      smaller = head;
      head = finisher;
      llpivot(head, smaller->next, larger, pivot);
      return;
    }

    head = nullptr;
  return;
}
