using namespace std;

// Time Complexity O(n) and Space Complexity O(1)
int longestPeak(vector<int> array) {
	
	if(array.size() < 3)
		return 0;
	int upperBound = array.size() - 1;
	int i = 1;
	int peakStart = 0;
	int peakEnd = 0;
	bool isPeakFound = false;
	int longestPeak = 0;
	
	for(; i < upperBound ; i++)
	{
		bool isPeak = array.at(i-1) < array.at(i) && array.at(i) > array.at(i+1);
		if(isPeak){
			isPeakFound = true;
		}
		
		if(array.at(i-1) == array.at(i))
			peakStart = i;
		
		if(!isPeakFound && array.at(i-1) >= array.at(i) && array.at(i) <= array.at(i+1))
			peakStart = i;
		
		if(isPeakFound && array.at(i-1) >= array.at(i) && array.at(i) <= array.at(i+1)){
			peakEnd = i + 1;
			longestPeak = max(longestPeak , (peakEnd - peakStart));
			peakStart = i;
			isPeakFound = false;
		}
	}
	
	if(isPeakFound)
		longestPeak = i - peakStart + 1;
	
  return longestPeak;
}