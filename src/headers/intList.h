#pragma once

class intList {
private:

	struct node {
		int data;
		node* next;
	};

	node* head;
	node* curr;
	node* temp;

public:
	intList();
	void addNode(int d);
	void deleteNode(int delD);
	void printList();
	int getCurrentData();
	void deleteHead();
	bool isEmpty();
	int getHeadData();
};