using namespace std;

// Time complexity O(2^n) and space complexity O(n)
int getFib(int n)
{
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return getFib(n-1) + getFib(n-2);
}

int getNthFib(int n) {
  return getFib(n);
}