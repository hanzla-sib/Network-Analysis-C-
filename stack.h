#pragma once
#include<iostream>
using namespace std;
#include"ADJlist.h"

class Stack {
public:
	node* top;
	Stack() {
		top = NULL;
	}
	void push(int val) {
		node* newnode = new node;
		newnode->data = val;
		newnode->next = top;
		top = newnode;
	}
	int pop() {
		int saveddata;
		if (top == NULL)
			cout << "Stack Underflow" << endl;
		else {

			saveddata = top->data;
			top = top->next;
		}
		return saveddata;
	}
	bool isempty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
};
