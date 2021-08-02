#include <vector>
using namespace std;

/*
This code is to sort the input in descending order
*/

// not being used for heap-sort
// this can be used to create heap or insert elements into heap
void insert(vector<int> &heap, int value)
{
	int index = heap.size();
	heap.push_back(value);
	while(index > 1 && heap.at(index/2) > value)
	{
		heap[index] = heap.at(index/2);
		index /= 2;
	}
	heap[index] = value;
}

// this is deleting root element and placing it in the end to create descending array
void deleteElement(vector<int> &heap, int size)
{
	int temp = heap.at(0);
	heap.at(0) = heap.at(size-1);
	int index = 0;
	while(index < size-1)
	{
		int indx = (index+1)*2-1;
		if(indx < size-1 && heap.at(indx) < heap.at(indx+1))
			indx = indx + 1;
		if(indx < size && heap.at(indx) > heap.at(index)){
			swap(heap.at(indx), heap.at(index));
			index = indx;
		}
		else
			break;
	}
	heap.at(size-1) = temp;
}

// this is creating min-heap
void createHeap(vector<int> &heap, int index)
{
	while(index >=0)
	{
		int parent = (index-1)/2;
		if(heap.at(parent) >= heap.at(index))
			break;
		swap(heap.at(parent) , heap.at(index));
		index = parent;
	}
}

void printArray(vector<int> array)
{
	for(int val : array)
		cout << val << " ";
	cout << endl;
}

// Time Complexity O(nlogn) and space complexity O(1)
vector<int> heapSort(vector<int> array) {
	printArray(array);
	for(int i = 0 ; i < array.size() ; i++)
		createHeap(array, i);
	printArray(array);
	for(int i = array.size() ; i > 0 ; i--)
	{
		deleteElement(array, i);
	}
	printArray(array);
	
  return array;
}
