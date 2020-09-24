#pragma once
#include "asrToken.h"

class List {
private:

	struct node {
		token data;
		node* next;
	};

	node* head;
	node* curr;
	node* temp;

public:
	List();
	void addNode(token d);
	void deleteNode(token delD);
	void printList();
	token getCurrentData();
	void deleteHead();
	bool isEmpty();
	token getHeadData();
};