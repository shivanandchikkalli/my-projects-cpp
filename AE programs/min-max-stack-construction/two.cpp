using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
	vector<int> stack = {};
	
	// To achieve O(1) time complexity for all the methods , 
	// we need to track the min and max value for each entry
	vector<int> minValue = {};
	vector<int> maxValue = {};
	
	// Time complexity O(1) and Space complexity O(1)
  int peek() {
    if(stack.size() > 0)
			return stack.back();
    return -1;
  }

	// Time complexity O(1) and Space complexity O(1)
  int pop() {
    if(stack.size() > 0){
			int top = stack.back();
			stack.pop_back();
			if(stack.size() == 0){
				minValue = {};
				maxValue = {};				
			}
			else{
				minValue.pop_back();
				maxValue.pop_back();				
			}
			return top;
		}
    return -1;
  }

	// Time complexity O(1) and Space complexity O(1)
  void push(int number) {
		if(stack.size() == 0){
			minValue.push_back(number);
			maxValue.push_back(number);
		}
		else {
			int newMin = min(number, minValue.back());
			int newMax = max(number, maxValue.back());
			minValue.push_back(newMin);
			maxValue.push_back(newMax);		
		}
    stack.push_back(number);
  }

	// Time complexity O(1) and Space complexity O(1)
  int getMin() {
    if(stack.size() > 0)
			return minValue.back();
    return -1;
  }

	// Time complexity O(1) and Space complexity O(1)
  int getMax() {
    if(stack.size() > 0)
			return maxValue.back();
    return -1;
  }
};