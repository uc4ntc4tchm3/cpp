/*max_heap for c++*/
#include <vector>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void max_heapify(std::vector<int> a, size_t size, size_t i)
{
	size_t left = (i + 1) * 2 - 1;
	size_t right = (i + 1) * 2;
	size_t largest = i;
	if (left < size && a[left] > a[largest])
		largest = left;
	if (right < size && a[right] > a[largest])
		largest = right;
	if(largest != i)
	{
		swap(a[i], a[largest]);
		max_heapify(a, size, largest);
	}
}


void build_max_heap(std::vector<int> a, size_t size)
{
	for (int i = size / 2; i >= 0; i--)
		max_heapify(a, size, i);
}


void heapsort(std::vector<int> a, size_t size)
{
	build_max_heap(a, size);
	size_t heap_size = size;
	for(int i = size - 1; i>0; i--)
	{
		swap(a[0], a[i]);
		heap_size--;
		max_heapify(a, heap_size, 0);
	}
}