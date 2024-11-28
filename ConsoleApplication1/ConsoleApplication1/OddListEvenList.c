#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node_t;

Node_t* insertNodeLL(Node_t* head, int data) {
	Node_t* temp = head;
	Node_t* newNode = malloc(sizeof(Node_t));
	newNode->data = data;
	newNode->next = NULL;
	if (!head) {
		return newNode;
	}
	else {
		while (temp->next) {

			temp = temp->next;
		}
		temp->next = newNode;
	}
	return head;
}

Node_t* oddEvenNodeStructuring(Node_t* head) {
	if (!head)
		return NULL;

	Node_t* odd = head;
	Node_t* even = head->next;
	Node_t* evenFirst = even;

	while (1) {

		if (!odd || !even || !odd->next) {
			odd->next = evenFirst;
			break;
		}
		//set the next pointer for odd
		odd->next = even->next;
		

		//set the next pointer for even
		if (odd->next) {
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		else {
			odd->next = evenFirst;
			even->next = NULL;
			break;
			
		}



	}
	return head;
}

//int main() {
//	Node_t* head = insertNodeLL(NULL, 10);
//    insertNodeLL(head, 20);
//    insertNodeLL(head, 30);
//    insertNodeLL(head, 40);
//    insertNodeLL(head, 50);
//    insertNodeLL(head, 60);
//    insertNodeLL(head, 70);
//    insertNodeLL(head, 80);
//    insertNodeLL(head, 90);
//    insertNodeLL(head, 100);
//
//	oddEvenNodeStructuring(head);
//
//	do {
//
//		printf("%d ", head->data);
//	} while ((head = head->next) != NULL);
//		return 0;
//}