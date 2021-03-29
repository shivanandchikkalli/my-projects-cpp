using namespace std;

// Time complexity O(n) and space complexity O(1)
int getNthFib(int n) {
  int lastNumber = 0;
	int secondLastNumber = 1;
	int counter = 2;
	int output = 0;
	if(n == 1)
		return lastNumber;
	else if(n == 2)
		return secondLastNumber;
	while(counter++ <= n)
	{
		output = lastNumber + secondLastNumber;
		secondLastNumber = lastNumber;
		lastNumber = output;
	}
  return output;
}