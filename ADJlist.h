#pragma once
#include<iostream>
using namespace std;
struct node {
	node* next;
	int data;
};
int sum = 0;
int sum1 = 0;
class Adjlist {
public:
	//int counter = 0;
	int j;
	int outcount = 0;
	int incount = 0;
	int counter1;
	node* head, * temp, * tail;
	int counter;
	//int sum;
	Adjlist() {
		head = NULL;
		temp = NULL;
		j = 0;
		counter = 0;
		tail = NULL;
		 counter1 = 0;
		//sum = 0;
	}
	void cretelist(int y) {
		temp = new node();
		temp->data = y;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;

		}
	}

	/*void delfirst() {
		node* ptr = head;
		head = head->next;
		ptr->next = NULL;
	}
	void dellast() {
		node* ptr = head;
		node* ptr2 = head;
		while (ptr->next != NULL) {
			ptr2 = ptr;
			ptr = ptr->next;
		}
		ptr2->next = NULL;
	}
	void delatmid(int i) {

	}*/

	bool empty() {
		if (head == NULL) {
			return true;
		}
		else
			return false;
	}


	void print() {
		
		node* curr = head;
		while (curr != NULL) {
			//cout << "->" << " " << "(" << curr->data << ")" << " ";
			counter++;
			curr = curr->next;
		}
		sum += counter;

	}
	void printundi() {
		node* curr = head;
		while (curr != NULL) {
			//cout << "->" << " " << "(" << curr->data << ")" << " ";
			counter1++;
			curr = curr->next;
		}
		sum1 += counter1;

	}
};