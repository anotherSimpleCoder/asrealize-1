#pragma once
#include "asrToken.h"

/*
	This class represents a linked list for ´tokens. It is used in the interpreter to store tokens, which are created by the interpreter to make a strcutured model of the instruction in the code.
*/
class List {
private:

	/*
	Declaring node structure, which is the atomic part of the list.
*/
	struct node {
		token data; //the token, which needs to be stored
		node* next; //the node's successor
	};

	node* head; //head pointer, which represents the head of the list
	node* curr; //current pointer, which will be used for list operations
	node* temp; //temporary pointer, which will be used for node modifying operations

public:
	/*
	Constructor of the List class, which is used to initialize an instance of the List class,
*/
	List();

	/*
	Adds a new node to the list.
	Parameter:
		- d: data, which should be added to lit
*/
	void addNode(token d);

	/*
	Deletes a node from the list.
	Parameter:
		- delD: data, which will be used to track the node.
*/
	void deleteNode(token delD);

	/*
	Prints the contents of the list.
*/
	void printList();

	/*
	Returns data of the node, where the curr pointer is referring to.
*/
	token getCurrentData();

	/*
	Deletes the head of the list and moves the head to the old head's successor.
*/
	void deleteHead();

	/*
	Return true, if the list is empty,(head pointer is referring to NULL).
*/
	bool isEmpty();

	/*
	Returns the data of the head node.
*/
	token getHeadData();
};