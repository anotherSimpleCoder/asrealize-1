#include <iostream>
#include "intList.h"

using namespace std;

intList::intList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void intList::addNode(int d) {
	node* n = new node;
	n->next = NULL;
	n->data = d;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}

		curr->next = n;
	}

	else {
		head = n;
	}
}

void intList::deleteNode(int delD) {
	node* delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->data != delD) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "Data not in list!" << endl;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete delPtr;

	}
}

void intList::printList() {
	curr = head;
	while (curr != NULL) {
		int s = curr->data;
		cout << s << endl;
		curr = curr->next;
	}
}

int intList::getCurrentData() {
	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	int d = curr->data;

	return d;
}

void intList::deleteHead() {
	if (head != NULL) {
		node* delPtr = NULL;
		temp = head->next;
		curr = head;
		delPtr = curr;
		delete delPtr;
		head = temp;
	}

	else {
		cout << "Cannot delete head from empty list" << endl;
	}

}

bool intList::isEmpty() {
	if (head == NULL) {
		return true;
	}

	else {
		return false;
	}
}

int intList::getHeadData() {
	curr = head;
	int d = curr->data;

	return d;
}