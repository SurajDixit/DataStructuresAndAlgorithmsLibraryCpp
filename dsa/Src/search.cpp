/*
Copyright (c) by Suraj.U.Dixit. All rights reserved.
Code written and published by Suraj U Dixit.
*/

#include "includes\search.h"
namespace searchingAlgorithms
{

	int Search::LinearSearch(int DataArray[], int Size, int SearchElement)
	{
		int flag = 0, position = 0;
		for (int i = 0; i < Size; i++)
		{
			if (SearchElement == DataArray[i])
			{
				flag = 1;
				position = i;
				break;
			}
			else
			{
				flag = 0;
			}
		}

		if (flag == 1)
		{
			//cout << "Found at position " << position + 1 << " in the array" << endl;
			return position;
		}
		else
		{
			cout << "Not found" << endl;
			return -1;
		}
	}
	int Search::BinarySearch(int DataArray[], int Size, int SearchElement)
	{
		int flag = 0;
		int position = 0;
		int upperBound = Size - 1;
		int lowerBound = 0;
		int midPoint = 0;
		int Temp = 0;
		
		for (int i = 0; i < Size; i++)
		{
			if (DataArray[i] == SearchElement)
				position = i;
		}

		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				if (DataArray[i] < DataArray[j])
				{
					Temp = DataArray[i];
					DataArray[i] = DataArray[j];
					DataArray[j] = Temp;
				}
			}
		}

		while (flag == 0)
		{
			if (upperBound < lowerBound)
			{
				flag = 0;
				break;
			}

			midPoint = lowerBound + ((upperBound - lowerBound) / 2);

			if (DataArray[midPoint] == SearchElement)
			{
				flag = 1;
				//position = midPoint;
				break;
			}
			else
			{
				if (DataArray[midPoint] < SearchElement)
				{
					lowerBound = midPoint + 1;
					flag = 0;
				}

				else
				{
					upperBound = midPoint - 1;
					flag = 0;
				}
			}


		}

		if (flag == 1)
		{
			//cout << "Found at position: " << position << endl;
			return position;
		}

		else
		{
			//cout << "Not found" << endl;
			return -1;
		}

	}
	int Search::InterPolationSearch(int Array[], int Size, int SearchElement)
	{
		int Temp = 0;
		int lowerBound = 0, upperBound = (Size - 1);
		int position = -1;
		
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] == SearchElement)
				position = i;
		}

		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				if (Array[i] < Array[j])
				{
					Temp = Array[i];
					Array[i] = Array[j];
					Array[j] = Temp;
				}
			}
		}

		while (lowerBound <= upperBound && SearchElement >= Array[lowerBound] && SearchElement <= Array[upperBound])
		{

			int pos = lowerBound + (((double)(upperBound - lowerBound)/(Array[upperBound] - Array[lowerBound]))*(SearchElement - Array[lowerBound]));

			if (Array[pos] == SearchElement)
			{
				return position;
			}
			if (Array[pos] < SearchElement)
				lowerBound = pos + 1;
			else
				upperBound = pos - 1;
		}
		return -1;
	}

	//Hash Table
	#define SIZE 100
	struct DataItem
	{
		int data;
		int key;
	};
	struct DataItem* hashArray[SIZE];
	struct DataItem* dummyItem;
	struct DataItem* item;

	int hashCode(int key) {
		return key % SIZE;
	}

	int Search::InsertKeyValue(int key, int data)
	{

			struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
			item->data = data;
			item->key = key;

			//get the hash
			int hashIndex = hashCode(key);

			//move in array until an empty or deleted cell
			while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
				//go to next cell
				++hashIndex;

				//wrap around the table
				hashIndex %= SIZE;
			}

			if (hashArray[hashIndex] = item)
			{
				printf("Successfully Entered Key -> %d",item->key);
				return 0;
			}
			else
			{
				printf("There was an error while Inserting Key -> %d", item->key);
				return -1;
			}
	}

	int Search::DisplayHash()
	{
		int i = 0;

		for (i = 0; i<SIZE; i++) {

			if (hashArray[i] != NULL)
				printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
			else
				printf(" ~~ ");
		}

		printf("\n");
		return 0;
	}

	struct DataItem *search(int key) {
		//get the hash
		int hashIndex = hashCode(key);

		//move in array until an empty
		while (hashArray[hashIndex] != NULL) {

			if (hashArray[hashIndex]->key == key)
				return hashArray[hashIndex];

			//go to next cell
			++hashIndex;

			//wrap around the table
			hashIndex %= SIZE;
		}

		return NULL;
	}

	int Search::SearchHash(int key)
	{
		item = search(key);
		if (item != NULL) {
			printf("Element Found\n");
			return item->data;
		}
		else {
			printf("Element not found\n");
			return -1;
		}
	}

	struct DataItem* del(struct DataItem* item) {
		int key = item->key;

		//get the hash
		int hashIndex = hashCode(key);

		//move in array until an empt
		while (hashArray[hashIndex] != NULL) {

			if (hashArray[hashIndex]->key == key) {
				struct DataItem* temp = hashArray[hashIndex];

				//assign a dummy item at deleted position
				hashArray[hashIndex] = dummyItem;
				return temp;
			}

			//go to next cell
			++hashIndex;

			//wrap around the table
			hashIndex %= SIZE;
		}

		return NULL;
	}

	int Search::DeleteHash(int key)
	{
		item = search(key);
		int valueOfKeyData = item->data;
		item = del(item);
		if (item == NULL)
		{
			printf("Error while deleting\n");
			return -1;
		}
		else
		{
			printf("Deleted 'Value -> %d' of 'key -> %d' Successfully\n",valueOfKeyData,key);
			return 0;
		}
	}

}
