using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
public:
  double median;
	vector<int> maxHeap = {};
	int maxHeapSize = 0;
	
	vector<int> minHeap = {};
	int minHeapSize = 0;

  void insert(int number) {
		if(minHeapSize == 0 && maxHeapSize == 0) {	
			insertIntoMaxHeap(number);
			maxHeapSize++;
		}
		else if(minHeapSize == 0 || maxHeapSize == 0) {
			if(minHeapSize == 0 && maxHeap.at(0) < number) {
				insertIntoMinHeap(number);
				minHeapSize++;
			}
			else if(minHeapSize == 0 && maxHeap.at(0) > number) {
				insertIntoMinHeap(maxHeap.at(0));
				removeFromMaxHeap();
				insertIntoMaxHeap(number);
				minHeapSize++;
			}
		}
    else if(number > maxHeap.at(0)) {
			if(abs(minHeapSize + 1 - maxHeapSize) < 2) {
				insertIntoMinHeap(number);
				minHeapSize++;				
			}
			else if(abs(minHeapSize + 1 - maxHeapSize) >= 2) {
				insertIntoMaxHeap(minHeap.at(0));
				removeFromMinHeap();
				insertIntoMinHeap(number);
				maxHeapSize++;				
			}
		}
    else if(number <= minHeap.at(0)) {
			if(abs(maxHeapSize + 1 - minHeapSize) < 2) {
				insertIntoMaxHeap(number);
				maxHeapSize++;				
			}
			else if(abs(maxHeapSize + 1 - minHeapSize) >= 2) {
				insertIntoMinHeap(maxHeap.at(0));
				removeFromMaxHeap();
				insertIntoMaxHeap(number);
				minHeapSize++;			
			}
		}
		
		if(minHeapSize == 0 || maxHeapSize == 0) {
			median = minHeapSize == 0 ? maxHeap.at(0) : minHeap.at(0);
		}
		else if((minHeapSize + maxHeapSize) % 2 == 0) {
			median = (double)(maxHeap.at(0) + minHeap.at(0)) / 2;
		}
		else
			median = minHeapSize > maxHeapSize ? minHeap.at(0) : maxHeap.at(0);
  }
	
	void insertIntoMaxHeap(int value) {
		maxHeap.push_back(value);
		int index = maxHeap.size() - 1;
		if(index == 0)
			return;
		createMaxHeap(index);
	}
	
	void createMaxHeap(int index) {
		while(index > 0 && maxHeap.at((index-1)/2) < maxHeap.at(index))
		{
			swap(maxHeap.at((index-1)/2) , maxHeap.at(index));
			index = (index-1)/2;
		}		
	}	
	
	void insertIntoMinHeap(int value) {
		minHeap.push_back(value);
		int index = minHeap.size() - 1;
		if(index == 0)
			return;
		createMinHeap(index);
	}
	
	void createMinHeap(int index) {
		while(index > 0 && minHeap.at((index-1)/2) > minHeap.at(index))
		{
			swap(minHeap.at((index-1)/2) , minHeap.at(index));
			index = (index-1)/2;
		}		
	}
	
	void removeFromMinHeap() {
		int currentIndex = 0;
		int heapSize = minHeapSize - 1;
		minHeap.at(currentIndex) = minHeap.at(heapSize);
		while(currentIndex < heapSize) {
			int replacingIndex = currentIndex*2+1;
			if(replacingIndex + 1 <= heapSize && minHeap.at(replacingIndex + 1) < minHeap.at(replacingIndex))
				replacingIndex++;
			if(replacingIndex < heapSize)
				swap(minHeap.at(replacingIndex), minHeap.at(currentIndex));
			currentIndex = replacingIndex;
		}
		minHeap.pop_back();
	}
	
	void removeFromMaxHeap() {
		int currentIndex = 0;
		int heapSize = maxHeapSize - 1;
		maxHeap.at(currentIndex) = maxHeap.at(heapSize);
		while(currentIndex <= heapSize) {
			int replacingIndex = currentIndex*2+1;
			if(replacingIndex + 1 <= heapSize && maxHeap.at(replacingIndex + 1) > maxHeap.at(replacingIndex))
				replacingIndex++;
			swap(maxHeap.at(replacingIndex), maxHeap.at(currentIndex));
			currentIndex = replacingIndex;
		}
		maxHeap.pop_back();
	}	

  double getMedian() { return median; }
};