#include <iostream>
using namespace std;

class heap
{

public:
  int arr[100];
  int size;

  heap()
  {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[parent] < arr[index])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  }

  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deletefromHeap()
  {
    if (size == 0)
    {
      cout << "nothing to delete" << endl;
      return;
    }
    arr[1] = arr[size];
    size--;

    // take root node to is correct position
    int i = 1;
    while (i < size)
    {
      int leftIndex = 2 * 1;
      int rightIndex = 2 * 1 + 1;

      if (leftIndex < size && arr[i] < arr[leftIndex])
      {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      }
      else if (rightIndex < size && arr[i] < arr[rightIndex])
      {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      }
      else
      {
        return;
      }
    }
  }
};

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;
  if (left <= n && arr[largest] < arr[left])
  {
    largest = left;
  }
  if (right <= n && arr[largest] < arr[right])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  int size = n;
  while (size > 1)
  {
    // step i swap
    swap(arr[size], arr[1]);
    size--;

    // step 2 swap
    heapify(arr, size, 1);
  }
}
int main()
{

  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(51);
  h.insert(54);
  h.print();

  return 0;
}