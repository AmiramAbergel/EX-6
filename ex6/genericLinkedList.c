/*******************************************
*  genericlinkedList.c                     *
*  ~~~~~~~~~~~~~~~~~~~                     *
*  Implementation of generic linked list   *
*  data structure                          *
*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include "genericLinkedList.h"
#include "/share/ex_data/ex6/virtualHeap.h"

/************************************
*    TYPE DEFINITIONS               *
************************************/ 

struct ListNode_st {
   Data data;
   ListNode next;
};

/************************************
*    FUNCTION DEFINITIONS           *
************************************/ 



/***********************************************************
  listNodeNext
  returns the next node in list
  param
  - listNode - list node
  return
  - pointer to next list node, or NULL if listNode==NULL
***********************************************************/
ListNode listNodeNext (ListNode listNode) {
   if(!listNode) return NULL;
   return listNode->next;
}

/***********************************************************
  listNodeData
  returns a pointer to the data object pointed to by list node
  param
  - listNode - list node
  return
  - pointer to the data object pointed to by list node, or NULL if listNode==NULL
***********************************************************/
Data listNodeData (ListNode listNode) {
   if(!listNode) return NULL;
   return listNode->data;
}

/***********************************************************
  listLength
  returns number of nodes in linked list starting from head
  param
  - head - list node where counting should start
  return
  - number of nodes downstream of head node (until next==NULL)
***********************************************************/
int listLength (ListNode head) {
   int count=0;
   /*** scan list until end (next==NULL) ***/
   while(head) {
      head = head->next;
      count++;
   }
   return count;
}

/***********************************************************
  listNodeFind
  finds node that holds given data value
  param
  - head - list node where searching should start
  return
  - list node downstream of head whose data is equal to given data,
    or NULL if no downstream node has data value
***********************************************************/
ListNode listNodeFind (ListNode head, Data val) {
   while (head) {
      if (head->data == val)
         return head;
      head = head->next;
   }
   /*** reach here only if val was not found ***/
   return NULL;
}

/***********************************************************
  newListNode
  creates new list node sith given data (allocation of node struct)
  param
  - val - data to initialize node with
  return
  - newly allocated list node, or NULL if allocation is not
	successful.
	Newly created node is a list of length 1 (next==NULL)
***********************************************************/
ListNode newListNode (Data val) {
   ListNode newElement = ourMalloc (sizeof (struct ListNode_st));

   /*** set structure members ***/
   if (newElement) {
      newElement->data = val;
      newElement->next = NULL;
   }

   /*** return NULL if allocation failed ***/
   return newElement;
}

/***********************************************************
  listNodeInsert
  inserts single node into list in given place
  param
  - listNode   - node in list, after which insertion takes place
  - singleNode - node (list of length 1) to insert after listNode
  return
  - 1 if insertsion is successful
	0 if one of the given nodes is NULL
	  or if singleNode has nodes donwstream of it.
***********************************************************/
int listNodeInsert (ListNode listNode, ListNode singleNode) {
   if (!listNode || !singleNode || singleNode->next)
      return 0;

   singleNode->next  = listNode->next;
   listNode->next = singleNode;

   return 1;
}

/***********************************************************
  listConcat
  concatenates two lists
  param
  - list1   - head of first list
  - list2   - head of second list
  return
  - pointer to head of concatenated list
  Attaches last node of list1 to head of list2 
***********************************************************/
ListNode listConcat (ListNode list1, ListNode list2) {
   ListNode node = list1;
   /*** if list1 is empty, simply return head of list2 ***/
   if(!list1) return list2;

   /*** find last node of list1 ***/
   while(node->next) node = node->next;

   node->next = list2;

   return list1;
}

/***********************************************************
  listNodeDisconnect
  removes node from list downstream of given head
  param
  - head       - head node of given list 
  - listNode   - node downstream of head to be removed from list
  return
  - 1 if removal is successful
	0 if one of the given nodes is NULL
      or if listNode is not downstream of head
***********************************************************/
int listNodeDisconnect (ListNode head, ListNode listNode) {
   ListNode curr = head, prev = NULL;

   /*** scan list, keeping pointer to previous node ***/   
   while (curr != NULL && curr != listNode) {
      prev = curr;
      curr  = curr->next;
   }

   /*** here is where we check input ***/
   /*** why do we check prev here?   ***/
   if (!curr || !prev) return 0;

   /*** disconnect ***/
   prev->next = curr->next;
   curr->next = NULL;

   return 1;
}

/***********************************************************
  listSplit
  splits list after given list node
  param
  - listNode - node in list, after which list is to be split
  return
  - list node that was after given node in list
    (head of new list), or NULL if input is NULL
***********************************************************/
ListNode listSplit (ListNode listNode) {
   ListNode nextNode;

   if(!listNode) return NULL;
   nextNode = listNode->next;
   listNode->next = NULL;
   return nextNode;
}

/***********************************************************
  freeList
  frees all memory allocated by list nodes downstream of
  given list node
  param
  - head - head of linked list
***********************************************************/
void freeList (ListNode head) {
   ListNode curr = head, prev = NULL;

   while (curr) {
      prev = curr;
      curr = curr->next;
      ourFree(prev);
   }
}

/***********************************************************
  freeListAndData
  frees all memory allocated by list nodes downstream of
  given list node, together with data objects (if not null)
  param
  - head - head of linked list
***********************************************************/
void freeListAndData (ListNode head) {
   ListNode curr = head, prev = NULL;

   while (curr) {
      prev = curr;
      curr = curr->next;
      if(prev->data) ourFree(prev->data);
      ourFree(prev);
   }
}

