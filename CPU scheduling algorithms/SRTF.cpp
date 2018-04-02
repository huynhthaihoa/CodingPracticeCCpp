#include<stdio.h>
typedef struct TNode
{
	int rmt;
	int pos;
	TNode* tNext;
};
typedef TNode* TNODE;

typedef struct QUEUE
{
	TNODE THead;
	TNODE TTail;
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
	int i,j;
	for(i = 0; i < n; ++i)
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
void Init(QUEUE &q)
{
	q.THead = q.TTail = NULL;
}
TNODE GetNode(int rmt, int pos)
{
	TNODE t = new TNode;
	if(t == NULL)
		return NULL;
	t->pos = pos;
	t->rmt = rmt;
	t->tNext = NULL;
	return t;
}
void Insert(QUEUE &q, TNODE t)
{
	if(q.THead == NULL)
	{
		q.THead = q.TTail = t;
		return;
	}
	else if(t->rmt <= q.THead->rmt)
	{
		t->tNext = q.THead;
		q.THead = t;
		return;
	}
	else if(t->rmt > q.TTail->rmt)
	{
		q.TTail->tNext = t;
		q.TTail = t;
		return;
	}
	else
	{
		TNODE p = q.THead;
		TNODE q = p->tNext;
		while(q->rmt < t->rmt)
		{
			p = q;
			q = q->tNext;
		}
		t->tNext = p->tNext;
		p->tNext = t;
	}
}
TNODE DeQueue(QUEUE &q)
{
	if(q.THead == NULL)
		return NULL;
	TNODE p = q.THead;
	q.THead = q.THead->tNext;
	if(q.THead == NULL)
	{
		q.TTail = NULL;
	}
	return p;
}
void DecreaseHead(QUEUE &q)
{
	TNODE p = DeQueue(q);
	if(p != NULL)
		Insert(q, GetNode(p->rmt - 1, p->pos));
}
void main()
{
	int *pn; 
	int *arr, *bur, *finish, *stat, *tat, *wt, i, n;
	int totwt = 0, tottat = 0; 
	int j = 0;
	QUEUE q;
	printf("Enter the number of processes:"); 
	scanf("%d", &n); 
	pn = new int[n];
	arr = new int[n];
	bur = new int[n];
	finish = new int[n];
	stat = new int[n];
	tat = new int[n];
	wt = new int[n];
	for(i = 0; i < n; ++i) 
	{ 
		printf("Enter the Process Name, Arrival Time & Burst Time:"); 
		scanf("%d%d%d", &pn[i], &arr[i], &bur[i]); 
	} 
	InterchangeSort(pn, arr, bur, n);
	Init(q);
	int l = arr[0];
	do
	{
	    DecreaseHead(q);
		if(q.THead != NULL && q.THead->rmt == 0)
	    {
			finish[q.THead->pos] = l;
	        DeQueue(q);
			if(q.THead == NULL && l < arr[j])
				l = arr[j];
	    }
		for(; l == arr[j]; ++j)
			Insert(q, GetNode(bur[j], j));
		l++;
    }
	while(q.THead != NULL);
	for(i = 0; i < n; ++i) 
	{ 
		tat[i] = finish[i] - arr[i];
		wt[i] = tat[i] - bur[i];
	} 
	printf("\nPName     Arrtime     Exectime    Waittime     TAT   Finish");
	for(int i = 0; i < n; ++i) 
	{ 
		printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d%s", pn[i], arr[i], bur[i], wt[i], tat[i], finish[i], i == n-1 ? "\n" : ""); 
	    totwt += wt[i]; 
		tottat += tat[i]; 
	}
	printf("\nAverage waiting time    Average turnaround time");
	printf("\n%6.2f\t%6.2f", (float)totwt / n, (float)tottat / n);
	delete pn;
	delete arr;
	delete bur;
	delete finish;
	delete tat;
	delete wt;
}
