/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#pragma once
#include "commonheaders.h"

namespace datastructures
{
	class queue
	{
		int front;
		int rear;
		int * dataArray;
		int sizeOfQueue;
	public :
		queue();
		int insert(int data);
		int setSize(int size);
		void display();
		int deleteData();
	};
}