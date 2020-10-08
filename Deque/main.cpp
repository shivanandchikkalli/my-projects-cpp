#include<iostream>

#include "dequeheader.h"

using namespace std;


int main(int argc, char* argv[])
{
        Deque<string> deque;

        deque.push_front("front-one");
        deque.push_front("front-two");
        deque.push_front("front-three");

        deque.push_back("front-zero");

        cout << "front element : " << deque.front() << endl;
        cout << "back element : " << deque.back() << endl;

        deque.pop_front();
        deque.pop_back();

        cout << "front element : " << deque.front() << endl;
        cout << "back element : " << deque.back() << endl;

        return 0;
}
