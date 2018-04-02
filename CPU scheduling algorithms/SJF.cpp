#include<stdio.h>

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}
void main()
{
	int *pn, *arrt, *burt, *stat, *fint, *tat, *wt;
	int n;
	int i;
	int pivot;
	int totwt = 0,tottat = 0; 
	int timelength;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	pn = new int[n];
	arrt = new int[n];
	burt = new int[n];
	stat = new int[n];
	fint = new int[n];
	tat = new int[n];
	wt = new int[n];
	for(i = 0; i < n; ++i) 
	{ 
		printf("Enter the Process Name, Arrival Time & burst Time:"); 
		scanf("%d%d%d", &pn[i], &arrt[i], &burt[i]); 
	} 
	for(i = 0; i < n; ++i)
	{
		timelength = (i > 0)? fint[i - 1]: arrt[i];
		pivot = i;
		for(int j = i + 1; j < n; ++j)
		{
			if(arrt[j] <= timelength && burt[j] < burt[i])
				pivot = j;
		}
		swap(&pn[i], &pn[pivot]);
		swap(&arrt[i], &arrt[pivot]);	
	    swap(&burt[i], &burt[pivot]);
		if(i  ==  0) 
			stat[i] = arrt[i]; 
		else
			stat[i] = (fint[i - 1] >= arrt[i])? fint[i - 1]:arrt[i]; 
		wt[i] = stat[i] - arrt[i]; 
		fint[i] = stat[i] + burt[i]; 
		tat[i] = fint[i] - arrt[i]; 
	} 
	printf("\nPName     Arrtime     Exectime    Waittime     TAT   Finish");
	for(i = 0; i < n; ++i) 
	{ 
		printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d%s", pn[i], arrt[i], burt[i], wt[i], tat[i], fint[i], i == n - 1 ? "\n" : ""); 
		totwt += wt[i]; 
		tottat += tat[i]; 
	}
	printf("\nAverage waiting time    Average turnaround time");
	printf("\n%6.2f\t%6.2f", (float)totwt / n, (float)tottat / n);
	delete pn;
	delete arrt;
	delete burt;
	delete stat;
	delete fint;
	delete tat;
	delete wt;
}