/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#include "includes\stack.h"

namespace datastructures
{
	stack::stack()
	{
		top = -1;
	}

	int stack::setSize(int size)
	{
		sizeOfStack = size;
		if (dataArray = new int[size])
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	int stack::push(int val)
	{
		if (top == sizeOfStack - 1)
		{
			cout << "stack overflow" << endl;
			return -1;
		}
		else
		{
			dataArray[++top] = val;
			return 0;
		}
	}

	

	int stack::peek()
	{
		return dataArray[top];
	}

	int stack::pop()
	{
		if (top == -1)
		{
			cout << "stack underflow" << endl;
			return -1;
		}
		else
		{
			return dataArray[top--];
		}
	}

}