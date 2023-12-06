#include<stdio.h>
#include<limits.h>

int heap[1000000], heapSize;

void init()
{
  heapSize = 0;
  heap[0] = -INT_MAX;
}

void Insert(int element)
{
  heapSize++;
  heap[heapSize] = element;
  int now = heapSize;
  while (heap[now / 2] > element)
  {
    heap[now] = heap[now / 2];
    now /= 2;
  }
  heap[now] = element;
}

int deletemin()
{
  int minelement, lastelement, child, now;
  minelement = heap[1];
  lastelement = heap[heapSize--];
  for (now = 1; now * 2 <= heapSize; now = child)
  {
    child = now * 2;
    if (child != heapSize && heap[child + 1] < heap[child])
      child++;

    if (lastelement > heap[child])
      heap[now] = heap[child];

    else
      break;
  }

  heap[now] = lastelement;
  return minelement;
}

int main()
{
  int number_of_elements;
  printf("program to demonstrate heap:\nenter the number of elements: ");
  scanf("%d", &number_of_elements);

  int iter, element;
  printf("enter the elements: ");
  
  for (iter = 0;iter < number_of_elements; iter++)
  {
    scanf("%d", &element);
    Insert(element);
  }

  for (iter = 0; iter < number_of_elements; iter++)
    printf("%d ", deletemin());

  printf("\n");
  return 0;
}
