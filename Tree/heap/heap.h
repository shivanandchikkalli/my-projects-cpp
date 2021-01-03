#ifndef _H_HEAP_
#define _H_HEAP_

class Heap
{
    private:
        int* array;
        int heap_size;
        int array_size;
    public:
        Heap();
        ~Heap();

        void Initialize(int size);

        int get_heap_size();

        void Insert(int value);
        void Delete();

        void Print();

        void HeapSort();
};

#endif