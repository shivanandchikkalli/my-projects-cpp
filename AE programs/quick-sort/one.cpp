#include <vector>
using namespace std;

int partition(vector<int> &array, int low, int high)
{
	int pivot = array.at(low);
	int i = low;
	int j = high;
	do
	{
		do { i++; }while(i < high && array.at(i) < pivot);
		do { j--; }while(j > low && array.at(j) > pivot);
		if(j > i)
			swap(array.at(i), array.at(j));
	}while(j > i);
	swap(array.at(low), array.at(j));
	return j;
}


void qSort(vector<int> &array, int low, int high)
{
	if(low < high)
	{
		int i = partition(array, low, high);
		qSort(array, low, i);
		qSort(array, i+1, high);
	}
}

vector<int> quickSort(vector<int> array) {
  qSort(array, 0, array.size());
  return array;
}