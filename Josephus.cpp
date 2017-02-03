#include "stdafx.h"
#include <iostream>

using namespace std;

struct lnode {
	int value;
	lnode *next;
	lnode(int) {}
	lnode(int val) {
		value = val;
		next = NULL;
	}
};


void addAtBack(lnode* list, int value) {
	lnode* head = list;
	lnode* startNode = list;
	lnode* newNode;
	newNode = new lnode(value);
	while (head->next != startNode) {
		head = head->next;
	}
	head->next = newNode;
	newNode->next = startNode;
}


int main() {
	
	lnode* list = new lnode(1);
	lnode* start = list;
	for (int i = 0; i < 99; i++) {
		addAtBack(list, i + 1);
	}
	while (list->next != start) {
		cout << list->value;
	}
	return 0;
}