#include "llrec.h"

// helper function
void llpivot_helper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if(head == nullptr) {
		return;
	}
  Node* curr = head;
	head = head->next;
	curr->next = nullptr;
	// if the value is less than or equal to the pivot, adds the pointer to the smaller linked list
	if(curr->val <= pivot) {
		Node* currSmaller = smaller;
		// if smaller is null, then sets the first value to the current item
		if(smaller == nullptr) {
			smaller = curr;
			currSmaller = smaller;
		}
		// otherwise adds to end of the LinkedList
		else {
			currSmaller->next = curr;
			currSmaller = currSmaller->next;
		}
		// recursive call
    llpivot_helper(head, currSmaller, larger, pivot);
	}
	// if the value is greater than the pivot, adds the pointer to the smaller linked list
	else if(curr->val > pivot) {
		Node* currLarger = larger;
		// if larger is null, then sets the first value to the current item
		if(larger == nullptr) {
			larger = curr;
			currLarger = larger;
		}
		// otherwise adds to end of the LinkedList
		else {
			currLarger->next = curr;
			currLarger = larger->next;
		}
		// recursive call
		llpivot_helper(head, smaller, currLarger, pivot);
	}
}


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
// sets smaller and larger to null and calls the helper function
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
	smaller = nullptr;
	larger = nullptr;
	llpivot_helper(head, smaller, larger, pivot);
}