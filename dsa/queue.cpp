/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/


#include "queue.h"

namespace datastructures
{

	queue::queue()
	{
		front = 0;
		rear = -1;
	}
	
	int queue::setSize(int size)
	{
		sizeOfQueue = size;
		dataArray = new int[size];
		return 0;
	}

	void queue::display()
	{
		if (front == 0 && rear == -1)
		{
			cout << "queue is empty" << endl;
		}

		if (front > rear)
		{
			cout << "\n-------Displaying the queue-----------" << endl;

			for (int i = 0; i <= rear; i++)
				cout << dataArray[i] << endl;
			for (int j = front; j <= sizeOfQueue - 1; j++)
				cout << dataArray[j] << endl;
		}

		else
		{
			cout << "\n-------Displaying the queue-----------" << endl;

			for (int i = front; i <= rear; i++)
			{
				cout << dataArray[i] << endl;
			}
		}
		
		cout << endl;
	}

	int queue::deleteData()
	{
		if ((front == 0) && (rear == -1))
		{
			cout << "Queue is empty" << endl;
		}

		int retr;
		
		if (front == rear)
		{
			retr = dataArray[front];
			rear = -1;
			front = 0;
		}
		else
		{
			if (front == sizeOfQueue - 1)
			{
				retr = dataArray[front];
				front = 0;
			}
			else
			{
				retr = dataArray[front++];
			}
		}

		cout << retr << " is deleted from the queue" << endl;
		return retr;

	}
	
	int queue::insert(int data)
	{
		if ((rear == sizeOfQueue - 1 && front == 0) || ( front > 0 && rear == front - 1))
		{
			cout << "\nQueue is full and " << data << " cannot be inserted." << endl;
			return -1;
		}
		else
		{
			if (rear == sizeOfQueue -  1 && front>0)
			{
				rear = 0;
				dataArray[rear] = data;
				cout << data << " - is inserted into the queue" << endl;
				return 0;
			}
			else
			{
				if ((front == 0 && rear == -1) || (rear != front - 1))
				{
					dataArray[++rear] = data;
					cout << data << " - is inserted into the queue" << endl;
					return 0;
				}
			}
		}
	}

}