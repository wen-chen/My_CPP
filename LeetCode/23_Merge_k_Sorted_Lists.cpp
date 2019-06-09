#include <vector>
#include<queue>
#include <iostream>


struct ListNode {
  int val;
  ListNode * next;
  ListNode(int x) : val(x), next(NULL) {}
};


/*
// Divide and Conquer
ListNode * mergeTwoLists(ListNode * list1, ListNode * list2) {
  if (list1 == NULL) {
    return list2;
  }

  if (list2 == NULL) {
    return list1;
  }
  
  // get minimum node and recursion
  ListNode * p = NULL;
  if (list1 -> val <= list2 -> val) {
    p = list1;
    p -> next = mergeTwoLists(list1 -> next, list2);
  } else {
    p = list2;
    p -> next = mergeTwoLists(list1, list2 -> next);
  }
  return p;
}


ListNode * mergeKLists(std::vector <ListNode *> & lists) {
  if (lists.size() == 0) {
    return NULL;
  }
  if (lists.size() == 1) {
    return lists[0];
  }
  if (lists.size() == 2) {
    return mergeTwoLists(lists[0], lists[1]);
  }
  
  // Divide and recursion
  int mid = lists.size() / 2;
  std::vector <ListNode *> left_lists, right_lists;
  for (int i = 0; i < mid; ++i) {
    left_lists.push_back(lists[i]);
  }
  for (int i = mid; i < lists.size(); ++i) {
    right_lists.push_back(lists[i]);
  }
  return mergeTwoLists(mergeKLists(left_lists), mergeKLists(right_lists));  
}
*/


// Priority Queue
struct cmp {
  bool operator() (ListNode * list1, ListNode * list2) {
    if (list1 -> val > list2 -> val) {
      return true;
    }
    return false;   
  }
};


ListNode * mergeKLists(std::vector <ListNode *> & lists) {
  std::priority_queue <ListNode *, std::vector < ListNode * >, cmp> pri_queue;
  
  // Load list into pri_queue
  for(int i = 0; i < lists.size(); ++i) {
    if (lists[i]) {
      pri_queue.push(lists[i]);
    }
  }
    
  // Create head and first node
  ListNode * head = new ListNode(0);
  ListNode * node = new ListNode(0);  
  head -> next = node;
  
  // Get minimum from queue and update pri_queue
  while ( ! pri_queue.empty() ) {    
    ListNode * minimum_list = pri_queue.top();
    pri_queue.pop();
    
    node -> next = minimum_list;
    node = node -> next;

    if (minimum_list -> next) {
      pri_queue.push(minimum_list -> next);
    }
  }

  // Ignore the first 2 node
  return head -> next -> next;
}


int main() {
  std::vector <ListNode *> lists;

  ListNode * a = new ListNode(1);
  a -> next = new ListNode(4);
  a -> next -> next = new ListNode(5);  
  lists.push_back(a);
  
  ListNode * b = new ListNode(1);
  b -> next = new ListNode(3);
  b -> next -> next = new ListNode(4);
  lists.push_back(b);
  
  ListNode * c = new ListNode(2);
  c -> next = new ListNode(6);
  lists.push_back(c);
  
  ListNode * p = mergeKLists(lists);
  while (p != NULL) {
    std::cout << p -> val << std::endl;
    p = p -> next;
  }
    
  return 0;
}
