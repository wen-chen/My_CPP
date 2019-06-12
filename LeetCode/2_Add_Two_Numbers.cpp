#include <iostream>


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  if (!l1) {
    return l2;
  }

  if (!l2) {
    return l1;
  }

  ListNode* head = new ListNode(0);
  ListNode* node = new ListNode(0);
  head->next = node;
  ListNode* p = l1;
  ListNode* q = l2;
  int sum = 0;

  while (p != NULL or q != NULL or sum > 0) {    
    if (p != NULL) {
      sum += p->val;
      p = p->next;
    }

    if (q != NULL) {
      sum += q->val;
      q = q->next;
    }

    node->next = new ListNode(sum % 10);
    node = node->next;
    sum = sum / 10;
    //std::cout << "sum:  " << sum << std::endl;
  }

  return head->next->next;
}


int main() {
  ListNode* l1 = new ListNode(2);
  l1 -> next = new ListNode(4);
  l1 -> next -> next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2 -> next = new ListNode(6);
  l2 -> next -> next = new ListNode(4); 

  ListNode* l_sum = addTwoNumbers(l1, l2);
  ListNode* p = l_sum;
  while (p != NULL) {
    std::cout << p->val << std::endl;
    p = p->next;
  }

  return 0;
}