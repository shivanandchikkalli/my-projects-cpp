#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
		int frst = (vector.size() - 2) / 2;
		for(int cIdx = frst ; cIdx >= 0 ; cIdx--)
			siftDown(cIdx, vector.size() - 1 , vector);
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
		int child1 = currentIdx * 2 + 1;
    while(child1 <= endIdx){
			int child2 = currentIdx * 2 + 2 <= endIdx ? currentIdx * 2 + 2 : -1;
			int idxToSwap = child1;
			if(child2 != -1 && heap.at(child2) < heap.at(child1))
				idxToSwap = child2;
			if(heap.at(idxToSwap) < heap.at(currentIdx)){
				swap(heap.at(idxToSwap), heap.at(currentIdx));
				currentIdx = idxToSwap;
				child1 = currentIdx * 2 + 1;
			}
			else
				return;
		}
  }

  void siftUp(int currentIdx, vector<int> &heap) {
		int parentIdx = (currentIdx-1) / 2;
    while(currentIdx > 0 && heap.at(currentIdx) < heap.at(parentIdx)){
			swap(heap.at(currentIdx), heap.at(parentIdx));
			currentIdx = parentIdx;
			parentIdx = (currentIdx-1) / 2;
		}
  }

  int peek() {
    return heap.at(0);
  }

  int remove() {
    swap(heap.at(0), heap.at(heap.size() - 1));
		int lastItem = heap.back();
		heap.pop_back();
		siftDown(0, heap.size() - 1, heap);
    return lastItem;
  }

  void insert(int value) {
		heap.push_back(value);
		siftUp(heap.size() - 1, heap);
  }
};