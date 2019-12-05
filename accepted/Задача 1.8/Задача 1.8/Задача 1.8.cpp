#include <iostream>
#include <math.h>

const float eps = 1e-6;

int main()
{
	printf("Enter the number of array elements: ");
	int num;
	scanf("%d", &num);
	float* arr = new float[num];
	for (int i = 0; i < num; i++)
	{
		printf("Enter the next element of the array: ");
		scanf("%f", &arr[i]);
	}
	int numOfZero = 0;
	for (int i = 0; i < num; i++)
	{
		if ((abs(arr[i]) <= eps))
			numOfZero++;
			
	}
	delete[] arr;
	printf("%d", numOfZero);
	return 0;

}