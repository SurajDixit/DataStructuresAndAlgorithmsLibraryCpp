/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#pragma once
#include "commonheaders.h"

namespace datastructures
{
	class linkedList
	{
	private:
		int info;
		linkedList * next;
		linkedList * start;
		linkedList * createNode();
	public:
		linkedList();
		int insertAtStart(int data);
		int insertAtEnd(int data);
		int deleteAtStart();
		int deleteAtEnd();
		void displayList();
		int insertAtPosition(int position, int data);
		int deleteAtPosition(int position);
		int totalNumberOfNodes();
		int returnDataFromPosition(int position);
		int swapData(int oldPosition, int newPosition);
		int sortList(int order);
	};
}
