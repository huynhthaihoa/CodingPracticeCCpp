#include<stdio.h>

typedef struct Process
{
	int pos;
	int rmt;
	Process *pNext;
};
typedef Process* P;
typedef struct Queue
{
	P pHead;
	P pTail;
};

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
	for(i = 0; i < n; ++i)
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
P GetProcess(int rmt,int pos)
{
	P t = new Process;
	if(t == NULL)
		return NULL;
	t->pos = pos;
	t->rmt = rmt;
	t->pNext = NULL;
	return t;
}
void Init(Queue &q)
{
	q.pHead = q.pTail = NULL;
}
void InsertTail(Queue &q,P np)
{
	if(q.pHead == NULL)
	{
		q.pHead = q.pTail = np;
		return;
	}
	else
	{
		q.pTail->pNext = np;
		q.pTail = np;
	}
}
P DeQueue(Queue &q)
{
	P p = q.pHead;
	q.pHead = q.pHead->pNext;
	if(q.pHead == NULL)
			q.pTail = NULL;
	p->pNext = NULL;
	return p;
}
void main()
{
	int *pn, n;
	int *arr, *rmt, *bur, *fint, *tat, *wt;
	int tquantum = 0, i, sum = 0,j = 0;
	int totwt = 0, tottat = 0;
	Queue q;
	P tmp;
	printf("Enter the number of processes:"); 
	scanf("%d", &n);
	pn = new int[n];
	arr = new int[n];
	bur = new int[n];
	rmt = new int[n];
	fint = new int[n];
	tat = new int[n];
	wt = new int[n];
	for(i = 0;i < n;i++) 
	{ 
		printf("Enter the Process Name,Arrival Time and Burst Time:"); 
		scanf("%d%d%d", &pn[i], &arr[i], &bur[i]); 
	} 
	InterchangeSort(pn, arr, bur, n);
	printf("Enter the time quantum:");
	scanf("%d", &tquantum);
	Init(q);
	//for(int i = 0;i < n;i++)
	//{
	//	rmt[i] = bur[i];
	//}
	do
	{
		if((q.pHead == NULL || q.pHead->rmt == 0 && q.pHead->pNext == NULL ) && sum < arr[j])
			sum = arr[j];
		if(sum >= arr[j])
		{
			while(sum >= arr[j] && j < n)
			{
				InsertTail(q, GetProcess(bur[j], j));
				j++;
			}
		}
		tmp = DeQueue(q);
		if(tmp->rmt > 0)
			InsertTail(q, tmp);
		if(q.pHead != NULL)
		{
			sum += (q.pHead->rmt > tquantum) ? tquantum : q .pHead->rmt;
		    q.pHead->rmt -= (q.pHead->rmt > tquantum) ? tquantum : q.pHead->rmt;
			if(q.pHead->rmt == 0)
				fint[q.pHead->pos] = sum; 
		}
	}
	while(j < n);
	for(i = 0;i < n;i++)  
	{ 
		tat[i] = fint[i] - arr[i];
		wt[i] = tat[i] - bur[i];
	}
	printf("\nPName    Arrivaltime     Exectime    Waittime     TAT   Fint");
	for(int i = 0; i < n; ++i) 
	{ 
		printf("\n%d\t%d\t%6d\t\t%6d\t%6d\t%6d%s", pn[i], arr[i], bur[i], wt[i], tat[i], fint[i], i == n - 1 ? "\n" : ""); 
	    totwt += wt[i]; 
		tottat += tat[i]; 
	}
	printf("\nAvg waittime    Avg turnaroundtime");
	printf("\n%6.2f\t\t%6.2f",(float)totwt / n, (float)tottat / n);
	delete pn;
	delete bur;
	delete rmt;
	delete fint;
	delete arr;
	delete tat;
	delete wt;
}