// ReverseSecondHalf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct lnode {
	int value;
	lnode *next;
};

void addAtFront(lnode* list, int value) {

	lnode* newNode;
	newNode = new lnode();
	newNode->value = value;
	newNode->next = list;
}

void addAtBack(lnode* list, int value) {
	lnode* head = list;
	lnode* newNode;
	newNode = new lnode();
	newNode->value = value;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = newNode;
}

void reverseSecondHalf(lnode* list) {
	lnode* fast = list;
	lnode* slow = list;
	lnode* pre = NULL;
	lnode* frontLastNode = NULL;
	lnode* next = NULL;

	while (slow->next != NULL) {
		if (fast->next != NULL && fast->next->next != NULL) {
			frontLastNode = slow;
			slow = slow->next;
			fast = fast->next->next;
			continue;
		}
		next = slow->next;
		slow->next = pre;
		pre = slow;
		slow = next;
	}
	slow->next = pre;
	frontLastNode->next = slow;
}

int main()
{
	lnode* list1 = new lnode();
	list1->value = 1;
	list1->next = NULL;
	for (int i = 0; i < 9; i++) {
		addAtBack(list1, i + 2);
	}
	reverseSecondHalf(list1);
	while (list1->next != NULL) {
		cout << list1->value << "->";
		list1 = list1->next;
	}
	cout << list1->value << endl;

	getchar();
	return 0;
}


