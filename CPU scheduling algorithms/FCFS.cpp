#include<stdio.h> 

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void InterchangeSort(int pn[], int arr[], int bur[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			if(arr[i] > arr[j])
			{
				swap(&pn[i], &pn[j]);
			    swap(&arr[i], &arr[j]);	
			    swap(&bur[i], &bur[j]);
			}	
		}
	}
} 
int main() 
{ 
	int *pn; 
	int *arr, *bur, *finish, *star, *tat, *wt;
	int i, n;
	int totwt = 0, tottat = 0; 
	printf("Enter the number of processes:"); 
	scanf("%d", &n);
	pn = new int[n];
	arr = new int[n];
	bur = new int[n];
	finish = new int[n];
	start = new int[n];
	tat = new int[n];
	wt = new int[n];
	for(i = 0; i < n; ++i) 
	{ 
		printf("Enter the Process Name, Arrival Time & Burst Time:"); 
		scanf("%d%d%d", &pn[i], &arr[i], &bur[i]); 
	} 
	InterchangeSort(pn, arr, bur, n);
	for(i = 0; i < n; ++i) 
	{ 
		if(i == 0) 
			start[i] = arr[i];  
		else 
			start[i] = (finish[i - 1] >= arr[i])? finish[i - 1] : arr[i];
		wt[i] = start[i] - arr[i]; 
		finish[i] = start[i] + bur[i]; 
		tat[i] = finish[i] - arr[i];
	} 
	printf("\nPName     Arrtime     Burtime    Start     TAT   Finish");
	for(i = 0; i < n; ++i) 
	{ 
		printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d%s", pn[i], arr[i], bur[i], start[i], tat[i], finish[i], i == n - 1 ? "\n" : ""); 
	    totwt += wt[i]; 
        tottat += tat[i];
	} 
	printf("\nAverage waiting time    Average turnaround time");
	printf("\n%6.2f\t%6.2f", (float)totwt / n, (float)tottat / n);
	delete pn;
	delete arr;
	delete bur;
	delete finish;
	delete start;
	delete tat;
	delete wt;
	return 0;
}
