using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
	vector<int> stack = {};
	int minValue = INT_MIN;
	int maxValue = INT_MAX;
	
	// Time complexity O(1) and Space complexity O(1)
  int peek() {
    if(stack.size() > 0)
			return stack.back();
    return -1;
  }
	
	void setNewMinValue() {
		minValue = stack.at(0);
		for(int val : stack){
			if(minValue > val)
				minValue = val;
		}
	}
	
void setNewMaxValue() {
		maxValue = stack.at(0);
		for(int val : stack){
			if(maxValue < val)
				maxValue = val;
		}
	}

	// Time complexity O(n) and Space complexity O(1)
  int pop() {
    if(stack.size() > 0){
			int top = stack.back();
			stack.pop_back();
			if(stack.size() == 0){
				minValue = INT_MIN;
				maxValue = INT_MAX;				
			}
			else if(top == minValue)
				setNewMinValue();
			else if(top == maxValue)
				setNewMaxValue();
			return top;
		}
    return -1;
  }

	// Time complexity O(1) and Space complexity O(1)
  void push(int number) {
		if(stack.size() == 0){
			minValue = number;
			maxValue = number;
		}
		else if(number < minValue)
			minValue = number;
		else if(number > maxValue)
			maxValue = number;
    stack.push_back(number);
  }

	// Time complexity O(1) and Space complexity O(1)
  int getMin() {
    if(stack.size() > 0)
			return minValue;
    return -1;
  }

	// Time complexity O(1) and Space complexity O(1)
  int getMax() {
    if(stack.size() > 0)
			return maxValue;
    return -1;
  }
};