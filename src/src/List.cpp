#include <iostream>
#include <cstdlib>
#include <string>
#include "List.h"

using namespace std;

string tokToStr(token t);

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::addNode(token d) {
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

void List::deleteNode(token delD) {
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

void List::deleteHead() {
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

void List::printList() {
	curr = head;
	while (curr != NULL) {
		string s = tokToStr(curr->data);
		cout << s << endl;
		curr = curr->next;
	}
}

string tokToStr(token t) {
	if (t == token::CB) {
		return "CB";
	}

	if (t == token::COL) {
		return "COL";
	}

	if (t == token::COM) {
		return "COM";
	}

	if (t == token::OB) {
		return "OB";
	}

	if (t == token::VAL) {
		return "VAL";
	}

	if (t == token::NUL) {
		return "";
	}
}

token List::getCurrentData() {
	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	token d = curr->data;
	
	return d;
}

bool List::isEmpty() {
	if (head == NULL) {
		return true;
	}

	else {
		return false;
	}
}

token List::getHeadData() {
	curr = head;
	token d = curr->data;

	return d;
}