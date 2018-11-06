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



/*
 *	minimum heap 
 *	
 *	void heapify(int arr[], int n, int i) 
{ 
    int smallest = i; // Initialize smalles as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is smaller than root 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
  
    // If right child is smaller than smallest so far 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
  
    // If smallest is not root 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, smallest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
 *
 *
 *
 *
 */


/*
 * heap sort linked list
 * 
 * //Heap Sort using Linked List
//This is the raw one
//This getRoot function will replace the root with number in the last node, after the main prints the largest number in the heap
//The heapSort function will reconstruct the heap
//addNode function is as same as in binary search tree
//Note addNode and heapSort are recursive functions
//You may wonder about the for loop used in main, this actually tells the depth of the tree (i.e log base2 N)
//With this value these functions find where to trverse whether left or right(direction), with help of macro GETBIT (0-left,1-right)


#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define GETBIT(num,pos) (num >> pos & 1)

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

int nodes;
node *first, *tmp, *current;

void addNode(node *,node *,int);
void swap(int *, int *);
void getRoot(node *, int);
void heapSort(node *);

int main()
{
    int num;
    int cont,i,j;

    while(1)                                                //It gets number from user if previous value is non zero number
    {
        printf("Enter a number\n");
        scanf("%d",&num);
        if(!num)                                            //i'm using 0 as terminating condition to stop adding nodes
            break;                                          //edit this as you wish

        current = (node *)malloc(sizeof(node));
        if(current ==  0)
            return 0;

        current->data = num;
        nodes++;

        for(i=nodes,j=-1; i; i >>= 1,j++);

        if(first == 0)
        {
            first = current;
            first->left = 0;
            first->right = 0;
        }
        else
            addNode(first,first,j-1);

        printf("Need to add more\n");

    }
    printf("Number of nodes added : %d\n",nodes);

    while(nodes)
    {
        printf(" %d -> ",first->data);                                        //prints the largest number in the heap

        for(i=nodes,j=-1; i; i >>= 1,j++);                                    //Updating the height of the tree
        getRoot(first,j-1);
        nodes--;

        heapSort(first);
    }       

    printf("\n\n");
    return 0;
}

void swap(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void addNode(node *tmp1,node *parent, int pos)
{
    int dirxn = GETBIT(nodes,pos);                                   // 0 - go left, 1 - go right

    if(!pos)
    {
        if(dirxn)
            tmp1->right = current;
        else
            tmp1->left = current;

        current->left = 0;
        current->right = 0;

        if(current->data > tmp1->data)
            swap(&current->data, &tmp1->data);
    }

    else
        if(dirxn)
            addNode(tmp1->right,tmp1,pos-1);
        else
            addNode(tmp1->left,tmp1,pos-1);

    if(tmp1->data > parent->data)
        swap(&parent->data,&tmp1->data);
}

void getRoot(node *tmp,int pos)
{
    int dirxn;

    if(nodes == 1)
        return ;

    while(pos)
    {
        dirxn = GETBIT(nodes,pos);

        if(dirxn)
            tmp = tmp->right;
        else
            tmp = tmp->left;
        pos--;
    }

    dirxn = GETBIT(nodes,pos);

    if(dirxn)
    {
        first->data = tmp->right->data;
        free(tmp->right);
        tmp->right = 0;
    }
    else
    {
        first->data = tmp->left->data;
        free(tmp->left);
        tmp->left = 0;
    }
}

void heapSort(node *tmp)
{
    if(!tmp->right && !tmp->left)
        return;

    if(!tmp->right)
    {
        if(tmp->left->data > tmp->data)
            swap(&tmp->left->data, &tmp->data);
    }
    else
    {
        if(tmp->right->data > tmp->left->data)
        {
            if(tmp->right->data > tmp->data)
            {
                swap(&tmp->right->data, &tmp->data);
                heapSort(tmp->right);
            }
        }           
        else
        {
            if(tmp->left->data > tmp->data)
            {
                swap(&tmp->left->data, &tmp->data);
                heapSort(tmp->left);
            }
        }
    }
}
 *
 */