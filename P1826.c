#include <stdio.h>
#include <stdlib.h>

int heap[100000];
int size = 0;

typedef struct
{
	int dis;
	int fuel;
} oil;
oil oilstation[10001];

void mergesort(oil arr[], int left, int mid, int right)
{

	int i;
	int sidx = left;
	int lidx = left;
	int ridx = mid + 1;
	oil *sortarr = (oil *)malloc(sizeof(oil) * (right + 1));

	while (lidx <= mid && ridx <= right)
	{
		if (arr[lidx].dis <= arr[ridx].dis) // 거리기준으로 정렬
			sortarr[sidx++] = arr[lidx++];
		else
			sortarr[sidx++] = arr[ridx++];
	}

	if (lidx > mid)
	{
		for (i = ridx; i <= right; i++)
			sortarr[sidx++] = arr[i];
	}
	else
	{
		for (i = lidx; i <= mid; i++)
			sortarr[sidx++] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortarr[i];

	free(sortarr);
}

void push(int data)
{
	int target = ++size;

	while (target != 1 && data > heap[target / 2])
	{
		heap[target] = heap[target / 2];
		target /= 2;
	}
	heap[target] = data;
}

int pop()
{
	int temp = heap[size];
	int root = heap[1];
	int i = 1;
	int parent = 1;
	int target = 2;
	size--;
	while (target <= size)
	{
		if (target < size && heap[target + 1] > heap[target])
			target++;
		if (temp >= heap[target])
			break;
		heap[parent] = heap[target];
		parent = target;
		target *= 2;
	}
	heap[parent] = temp;
	return root;
}

void merge(oil arr[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		merge(arr, left, mid);
		merge(arr, mid + 1, right);
		mergesort(arr, left, mid, right);
	}
}

int N, L, P, now, cnt;

int main(void)
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d%d", &oilstation[i].dis, &oilstation[i].fuel);

	scanf("%d%d", &L, &P);
	merge(oilstation, 0, N - 1);

	while (L > P)
	{
		while (oilstation[now].dis <= P)
		{
			if (now == N)
				break;
			push(oilstation[now].fuel);
			now++;
		}
		if (size == 0)
			break;

		cnt++;
		P += pop();
	}
	printf("%d\n", L > P ? -1 : cnt);

	return 0;
}