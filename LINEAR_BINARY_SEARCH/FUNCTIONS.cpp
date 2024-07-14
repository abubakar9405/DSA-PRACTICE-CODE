#include<iostream>
using namespace std;
int linearsearch(int arr[], int size, int num) {
	for (int  i = 0; i < size; i++)
	{
		if (arr[i]==num)
		{
			cout << "element found at index: "<<i+1;
		}
	}
	return -1;
}
int   binarysearch(int arr[], int size, int num) {
	int low, mid, high;
	low = 0;
	high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == num)
		{
			cout <<arr[mid];
			return mid;
		}
		if (arr[mid] > num)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}



}

int main() {
	//define your main to use the above defined functions
	//NOTE: for binary search your array must be sorted.

	/*int* ptr = new int[10];
	for (int  i = 0; i < 7; i++)
	{
		cin >> ptr[i];
	}
	binarysearch(ptr, 7, 1);
	return 0;*/
}