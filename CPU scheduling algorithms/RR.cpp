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
	int *pn; 
	int *bur, *rmt, *finish, *stat, *tat, *wt;
	int i, n;
	int tquantum = 0;
	int totwt = 0,tottat = 0; 
	int j = 0,sum = 0;
	printf("Enter the number of processes:"); 
	scanf("%d", &n); 
	pn = new int[n];
	bur = new int[n];
	rmt = new int[n];
	finish = new int[n];
	stat = new int[n];
	tat = new int[n];
	wt = new int[n];
	for(i = 0; i < n; ++i) 
	{ 
		printf("Enter the Process Name,Burst Time:"); 
		scanf("%d%d", &pn[i], &bur[i]); 
	} 
	printf("Enter the time quantum:");
	scanf("%d", &tquantum);
	for(int i = 0; i < n; ++i)
	{
		rmt[i] = bur[i];
	}
	printf("Proc  Start  Stop\n");
	int test = 0;
	while(test < n)
	{
		if(rmt[j % n] > 0)
		{
			printf("%d\t%d\t", pn[j % n], sum);
			test = 0;
			if(rmt[j % n] == bur[j % n])
				stat[j % n] = sum;
			sum += (rmt[j % n] > tquantum) ? tquantum : rmt[j % n];
			printf("%d\n", sum);
		    rmt[j % n] -= (rmt[j % n] > tquantum) ? tquantum : rmt[j % n];
		    if(rmt[j % n] == 0)
				finish[j % n] = sum;
		}
		else
			test++;
		j++;
	}
	for(i = 0; i < n; ++i)  
	{ 
		tat[i] = finish[i];
		wt[i] = tat[i] - bur[i];
	}
	printf("\nPName         Exectime    Waittime     TAT   Finish");
	for(int i = 0; i < n; ++i) 
	{ 
		printf("\n%d\t%6d\t\t%6d\t%6d\t%6d%s", pn[i], bur[i], wt[i], tat[i], finish[i], i == n - 1 ? "\n" : ""); 
	    totwt += wt[i]; 
		tottat += tat[i]; 
	}
	printf("\nAvg waittime    Avg turnaroundtime");
	printf("\n%6.2f\t\t%6.2f", (float)totwt / n, (float)tottat / n);
	delete pn;
	delete bur;
	delete rmt;
	delete finish;
	delete stat;
	delete tat;
	delete wt;
}