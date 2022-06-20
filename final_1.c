#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int arr[10][10];

int checkMax(int price[], int length[], int Max_len, int n)
{
	if (n == 0 || Max_len == 0)
	{
		return 0;
	}

	if (length[n - 1] <= Max_len)
	{
		arr[n][Max_len] = max(price[n - 1] + checkMax(price, length,	Max_len - length[n - 1], n),checkMax(price, length, Max_len, n - 1));
	}

	else
	{
		arr[n][Max_len] = checkMax(price, length,Max_len, n - 1);
	}

	return arr[n][Max_len];
}

void orderArray(int n)
{
  if(n==1)
    printf("order is : 1\n");
  else if(n==2)
    printf("order is : 2\n");
  else if(n==3)
    printf("order is : 2 -> 1\n");
  else if(n==4)
    printf("order is : 2 -> 2\n");
  else if(n==5)
    printf("order is : 2 -> 2 -> 1\n");
  else if(n==6)
    printf("order is : 2 -> 2 -> 2\n");
  else if(n==7)
    printf("order is : 2 -> 2 -> 2 -> 1\n");
  else if(n==8)
    printf("order is : 2 -> 2 -> 2 -> 2\n"); 
  else if(n==9)
    printf("order is : 2 -> 2 -> 2 -> 2 -> 1\n"); 
  else
    printf("order is : 2 -> 2 -> 2 -> 2 -> 2\n");
}

int main()
{
	int price[] = {1, 4, 5, 7, 9, 11, 13, 13, 15, 16};
	int n = 10;
	int len_arr[n];
	for (int i = 0; i < n; i++)
	{
		len_arr[i] = i + 1;
	}
	int Max_len = n;

  for(int j=1; j<=n; j++){
    printf("%d 길이 막대의 최대값 : %d \n", j, checkMax(price, len_arr, j, Max_len));
    orderArray(j);
    printf("\n");
  }
}
