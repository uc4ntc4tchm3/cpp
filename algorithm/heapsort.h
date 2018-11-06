#pragma once
/*max_heap for c*/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void max_heapify(int *a, int size, int i)
{
	int left = (i + 1) * 2 - 1;
	int right = (i + 1) * 2;
	int largest = i;

	if (left < size && a[left] > a[largest])
		largest = left;
	if (right < size && a[right] > a[largest])
		largest = right;
	if (largest != i)
	{
		swap(&a[i], &a[largest]);
		max_heapify(a, size, largest);
	}
}

void build_max_heap(int *a, int size)
{
	for (int i = size / 2; i >= 0; i--)
		max_heapify(a, size, i);
}

void heapsort(int *a, int size)
{
	build_max_heap(a, size);
	int heap_size = size;
	for(int i = size -1 ; i>0; i--)
	{
		swap(&a[0], &a[i]);
		heap_size--;
		max_heapify(a, heap_size, 0);
	}
}