#include <stdio.h>

typedef struct SinglyLinkedListNode {
	int data;
	struct SinglyLinkedListNode* next;
}SinglyLinkedListNode_t;

SinglyLinkedListNode_t* insertNodeLL2(SinglyLinkedListNode_t **head, int data) {
	SinglyLinkedListNode_t* newNode = malloc(sizeof(SinglyLinkedListNode_t)), *temp = *head;
	newNode->data = data;
	newNode->next = NULL;

	if (!*head)
		*head = newNode;
	else
	{
		do {

			if(temp->next)
				temp = temp->next;
			else
			{
				temp->next = newNode;
				break;
			}
		} while (1);
	}
	return *head;

}

void printLL(SinglyLinkedListNode_t* head) {
	if (!head)
		return;
	printf("\nLinkedList printing:");
	do {
		printf("%d ", head->data);

	} while ((head = head->next) != NULL);
}

/*Reverse at the count of k*/
SinglyLinkedListNode_t* reverseLL(SinglyLinkedListNode_t* head, int k) {
	/*if (!head || !head->next)
		return head;

	SinglyLinkedListNode_t* rest = reverseLL(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;*/

	if (!head || k == 1)
		return head;

	SinglyLinkedListNode_t* dummy = malloc(sizeof(SinglyLinkedListNode_t));
	SinglyLinkedListNode_t* curr = dummy, *prev = dummy, *next = dummy;
	dummy->next = head;

	int count = 0;
	while (curr->next)
	{
		curr = curr->next;
		count++;
	}

	while (count >= k) {
		curr = prev->next;
		next = curr->next;
		for (int i = 1; i < k; i++) {
			curr->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = curr->next;
		}
		prev = curr;
		count -= k;
	}
	return dummy->next;
}

//int main() {
//	SinglyLinkedListNode_t* head = NULL;
//	insertNodeLL2(&head, 10);
//	insertNodeLL2(&head, 20);
//	insertNodeLL2(&head, 30);
//	insertNodeLL2(&head, 40);
//	insertNodeLL2(&head, 50);
//	insertNodeLL2(&head, 60);
//	insertNodeLL2(&head, 70);
//	insertNodeLL2(&head, 80);
//	printLL(head);
//	head = reverseLL(head, 3);
//	printLL(head);
//	return 0;
//}