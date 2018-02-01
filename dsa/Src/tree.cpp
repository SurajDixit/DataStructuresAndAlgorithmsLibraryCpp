/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#include "includes\tree.h"

namespace datastructures
{
	tree::tree()
	{
		root = createNode();
		root->info = 0;
		root->right = NULL;
		root->left = NULL;
	}
	tree * tree::createNode()
	{
		tree * newnode;
		newnode = (tree *)malloc(sizeof(tree));
		newnode->info = 0;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	void tree::insertRoot(int key)
	{
		if (root->info == 0)
		{
			root->info = key;
		}
		else
		{
			cout << "Already inserted" << endl;
		}
	}
	void * tree::addNodeToRight(tree * node, tree * rootForThisInstance)
	{
		if (rootForThisInstance->right == NULL)
		{
			rootForThisInstance->right = node;
		}
		else
		{
			tree * testnode = createNode();
			testnode = rootForThisInstance->right;
			if (node->info < testnode->info)
			{
				addNodeToLeft(node, testnode);
			}
			else
				addNodeToRight(node, testnode);
		}
		return 0;
	}
	void * tree::addNodeToLeft(tree * node, tree * rootForThisInstance)
	{
		if (rootForThisInstance->left == NULL)
		{
			rootForThisInstance->left = node;
		}
		else
		{
			tree * testnode = createNode();
			testnode = rootForThisInstance->left;
			if (node->info < testnode->info)
			{
				addNodeToLeft(node, testnode);
			}
			else
			{
				addNodeToRight(node, testnode);
			}
		}
		return 0;
	}
	void tree::displayInOrder()
	{
		cout << "In-order Traversal : ";
		inOrder(root);
		cout << endl;
	}
	void * tree::inOrder(tree * rootForThisInstance)
	{
		if (rootForThisInstance != NULL)
		{
			inOrder(rootForThisInstance->left);
			cout << rootForThisInstance->info << " ";
			inOrder(rootForThisInstance->right);
		}
		return 0;
	}
	void tree::displayPreOrder()
	{
		cout << "Pre-order Traversal : ";
		preOrder(root);
		cout << endl;
	}
	void * tree::preOrder(tree * rootForThisInstance)
	{
		if (rootForThisInstance != NULL)
		{
			cout << rootForThisInstance->info << " ";
			preOrder(rootForThisInstance->left);
			preOrder(rootForThisInstance->right);
		}
		return 0;
	}
	void tree::displayPostOrder()
	{
		cout << "Post-order Traversal : ";
		postOrder(root);
		cout << endl;
	}
	void tree::insertLeaf(int key)
	{
		if (root->info == 0)
		{
			exit(0);
		}
		tree * node = createNode();
		node->info = key;
		if (node->info < root->info)
			addNodeToLeft(node, root);
		else if (node->info > root->info)
			addNodeToRight(node, root);
	}
	void * tree::postOrder(tree * rootForThisInstance)
	{
		if (rootForThisInstance != NULL)
		{
			postOrder(rootForThisInstance->left);
			postOrder(rootForThisInstance->right);
			cout << rootForThisInstance->info << " ";
		}
		return 0;
	}
}
