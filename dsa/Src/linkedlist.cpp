/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#include "includes\linkedlist.h"

namespace datastructures 
{

	linkedList::linkedList()
	{
		start = createNode();
		start->info = 0;
		start->next = NULL;
	}

	linkedList * linkedList::createNode()
	{
		linkedList * newnode;
		if(newnode = (linkedList *)malloc(sizeof(linkedList)))
		{
			return newnode;
		}
		else
		{
			return NULL;
		}	
	}

	int linkedList::insertAtStart(int data)
	{
		linkedList * newnode = createNode();

		if (newnode == NULL)
			return -1;

		newnode->info = data;
		newnode->next = NULL;

		if (start->info == 0)
		{
			start->next = newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = start->next;
			start->next = newnode;
		}

		start->info++;
		cout << "data: " << newnode->info << " inserted in the Linkedlist." << endl;
		return 0;
	}

	int linkedList::insertAtEnd(int data)
	{
		linkedList * newnode = createNode();

		if (newnode == NULL)
			return -1;

		newnode->info = data;
		newnode->next = NULL;

		linkedList * tempnode = createNode();

		if (tempnode == NULL)
			return -1;

		tempnode = start->next;

		while (tempnode->next != NULL)
		{
			tempnode = tempnode->next;
		}

		tempnode->next = newnode;
		start->info++;
		cout << "data: " << newnode->info << " inserted in the Linkedlist." << endl;
		return 0;
	}

	int linkedList::deleteAtStart()
	{
		linkedList * tempnode = createNode();

		if (tempnode == NULL)
			return -1;

		tempnode = start->next;
		int data = tempnode->info;
		start->next = tempnode->next;
		cout << "data: " << data << " has been deleted from Linkedlist." << endl;
		free(tempnode);
		start->info--;
		return data;
	}

	int linkedList::deleteAtEnd()
	{
		linkedList * tempnode = createNode();

		if (tempnode == NULL)
			return -1;

		tempnode = start->next;

		while (tempnode->next->next != NULL)
		{
			tempnode = tempnode->next;
		}

		linkedList * lastnode = createNode();

		if (lastnode == NULL)
			return -1;

		lastnode = tempnode->next;
		tempnode->next = NULL;
		int data = lastnode->info;
		cout << "data: " << data << " has been deleted from the Linkedlist" << endl;
		free(lastnode);
		start->info--;
		return data;
	}

	void linkedList::displayList()
	{
		cout << "\n-------Displaying Nodes---------" << endl;
		linkedList * temp = createNode();
		temp = start->next;
		while (temp->next != NULL)
		{
			cout << temp->info << "->";
			temp = temp->next;
		}

		cout << temp->info << endl;
		cout << endl;
		//return start;
	}

	int linkedList::insertAtPosition(int position, int data)
	{
		linkedList * newnode = createNode();

		if (newnode == NULL)
			return -1;

		newnode->info = data;
		newnode->next = NULL;

		linkedList * temp = createNode();

		if (newnode == NULL)
			return -1;

		temp = start->next;

		for (int i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}

		newnode->next = temp->next;
		temp->next = newnode;

		cout << "data: " << data << " inserted at position: " << position << endl;
		start->info++;
		return 0;
	}

	int linkedList::deleteAtPosition(int position)
	{
		if (position == start->info)
		{
			cout << "There is no node at position: " << position << endl;
			return -1;
		}

		else if (position < 0)
		{
			cout << "There is no node at position: " << position << endl;
			return -1;
		}

		else
		{
			linkedList * temp = createNode();

			if (temp == NULL)
				return -1;

			temp = start->next;

			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next;
			}

			linkedList * deletenode = createNode();

			if (deletenode == NULL)
				return -1;

			deletenode = temp->next;
			int retr = deletenode->info;
			cout << "data: " << deletenode->info << " deleted from position: " << position << endl;
			temp->next = temp->next->next;
			free(deletenode);
			start->info--;
			return retr;
		}
	}

	int linkedList::totalNumberOfNodes()
	{
		cout << "Total Nodes: " << start->info << "\n" << endl;
		return start->info;
	}

	int linkedList::returnDataFromPosition(int position)
	{
		if (position == start->info)
		{
			cout << "There is no node at position: " << position << endl;
			return -1;
		}

		else if (position < 0)
		{
			cout << "There is no node at position: " << position << endl;
			return -1;
		}

		else
		{

			linkedList * tempnode = createNode();

			if (tempnode == NULL)
				return -1;

			tempnode = start->next;
			for (int i = 0; i < position - 1; i++)
			{
				tempnode = tempnode->next;
			}
			return tempnode->next->info;
		}
	}

	//Swaps the content between 2 nodes
	int linkedList::swapData(int oldPosition, int newPosition)
	{
		cout << "Swapping Data from given positions....." << endl;

		linkedList * oldNode = createNode();
		linkedList * newNode = createNode();
		linkedList * temp = createNode();

		if (oldPosition >= start->info || newPosition >= start->info || oldPosition < 0 || newPosition < 0)
			return -1;

		if (oldNode == NULL)
			return -1;

		if (newNode == NULL)
			return -1;

		if (temp == NULL)
			return -1;

		oldNode = newNode = start->next;

		//traverse to previous node of the given position
		for (int i = 0; i < oldPosition; i++)
		{
			oldNode = oldNode->next;
		}

		for (int i = 0; i < newPosition; i++)
		{
			newNode = newNode->next;
		}

		//Swapping the data
		temp->info = oldNode->info;
		oldNode->info = newNode->info;
		newNode->info = temp->info;
		//swapping done

		cout << "Data Swapped....." << endl;
		return 0;
	}

	//Sorts the complete List
	int linkedList::sortList(int order)
	{
		cout << "Sorting......" << endl;

		linkedList * firstNode = createNode();
		linkedList * lastNode = createNode();

		if (firstNode == NULL)
			return -1;

		if (lastNode == NULL)
			return -1;

		int tempData = 0;
		int isSwapped = 0;

		lastNode = NULL;
		
		//Bubble Sort

		//Ascending Order
		if (order == 0)
		{
			cout << "Ascending Order...." << endl;
			do
			{
				firstNode = start->next;
				isSwapped = 0;

				while (firstNode->next != lastNode)
				{
					if (firstNode->info > firstNode->next->info)
					{
						tempData = firstNode->info;
						firstNode->info = firstNode->next->info;
						firstNode->next->info = tempData;
						isSwapped = 1;
					}
					firstNode = firstNode->next;
				}
				lastNode = firstNode;
			} while (isSwapped);
		}

		//Descending Order
		else if (order == 1)
		{
			cout << "Descending Order...." << endl;
			do
			{
				firstNode = start->next;
				isSwapped = 0;

				while (firstNode->next != lastNode)
				{
					if (firstNode->info < firstNode->next->info)
					{
						tempData = firstNode->info;
						firstNode->info = firstNode->next->info;
						firstNode->next->info = tempData;
						isSwapped = 1;
					}
					firstNode = firstNode->next;
				}
				lastNode = firstNode;
			} while (isSwapped);
		}

		else
		{
			return -1;
		}

		//Bubble Sort

		cout << "Sorting finished........." << endl;

		return 0;
	}
}

