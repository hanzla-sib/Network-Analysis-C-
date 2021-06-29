#pragma once
#include<iostream>
using namespace std;
#include"ADJlist.h"
class queue {


public:
	node* front, * rear;
	queue()
	{
		front = rear = NULL;
	}
	void enQueue(int x)
	{


		node* temp = new node;
		temp->data = x;
		temp->next = NULL;
		if (front == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	int deQueue()
	{
		int save;
		node* temp = front;
		save = temp->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;

		delete (temp);
		return save;
	}

	bool empty()
	{
		if (front == NULL && rear == NULL)
			return true;
		else
			return false;
	}
};
