#include<iostream>

#include "queueheader.h"

using namespace std;

int main(int argc, char* argv[])
{
	Queue<int> queue;

	queue.enqueue(100);
	queue.enqueue(200);
	queue.enqueue(300);

	queue.dequeue();

	cout << "front of the queue : " << queue.front() << endl;

	return 0;
}
