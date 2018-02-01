/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#include "commonheaders.h"

namespace datastructures
{
	class stack
	{
	private:
		int sizeOfStack;
		int * dataArray;
		int top;
	public:
		stack();
		int push(int val);
		int setSize(int size);
		int peek();
		int pop();
	};
}

