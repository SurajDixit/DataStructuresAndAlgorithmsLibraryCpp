/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#pragma once
#include "commonheaders.h"

namespace datastructures
{
	class tree
	{

	private:

		int info;
		tree * root;
		tree * left;
		tree * right;
		void * postOrder(tree * rootForThisInstance);
		void * preOrder(tree * rootForThisInstance);
		void * inOrder(tree * rootForThisInstance);
		void * addNodeToLeft(tree * node, tree * rootForThisInstance);
		void * addNodeToRight(tree * node, tree * rootForThisInstance);

	public:

		tree();
		tree * createNode();
		void insertRoot(int key);
		void displayInOrder();
		void displayPreOrder();
		void displayPostOrder();
		void insertLeaf(int key);
	};
}