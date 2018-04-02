#include<stdio.h>

typedef struct TNODE
{
	int rmt;
	int pos;
	int prior;
};

typedef struct QUEUE
{
	TNODE a[10];
	int n;
};
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void InterchangeSort(int pn[], int arr[], int bur[],int prior[], int n)
{
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = i + 1; j < n; ++j)
		{
			if(arr[i]>arr[j] || (arr[i] == arr[j] && prior[i] < prior[j]))
			{
				swap(&pn[i], &pn[j]);
			    swap(&arr[i], &arr[j]);	
			    swap(&bur[i], &bur[j]);
				swap(&prior[i], &prior[j]);
			}	
		}
}
TNODE GetTNode(int rmt,int pos,int prior)
{
	TNODE t;
	t.pos = pos;
	t.prior = prior;
	t.rmt = rmt;
	return t;
}
void Init(QUEUE &q)
{
	q.n = 0;
}
void Insert(QUEUE &q,TNODE t)
{
	if(q.n == 0)
	{
		q.n = 1;
		q.a[0] = t;
		return;
	}
	else		
	{
		int k = 0;
		while((t.prior < q.a[k].prior) && k < q.n)
		{
			k++;
		}
		for(int i = q.n;i > k;i--)
		{
			q.a[i] = q.a[i - 1];
		}
		q.a[k] = t;
		q.n++;
	}
}
void DeQueue(QUEUE &q)
{
	for(int i = 0;i < q.n - 1;i++)
	{
		q.a[i] = q.a[i + 1];
	}
	q.n--;
}
void DecreaseHead(QUEUE &q)
{
	if(q.n > 0)
		q.a[0].rmt--;
}
void main()
{
	int pn[10]; 
	int arr[10],bur[10],finish[10],prior[10],tat[10],wt[10],i,n;
	int totwt = 0,tottat = 0; 
	int j = 0;
	QUEUE q;
	printf("Enter the number of processes:"); 
	scanf("%d",&n); 
	for(i = 0;i < n;i++) 
	{ 
		printf("Enter the Process Name, Arrival Time,Burst Time and Priority:"); 
		scanf("%d%d%d%d",&pn[i],&arr[i],&bur[i],&prior[i]); 
	} 
	InterchangeSort(pn,arr,bur,prior,n);
	Init(q);
	int l = arr[0];
	do
	{
	    DecreaseHead(q);
		if(q.n != 0 && q.a[0].rmt == 0)
	    {
			finish[q.a[0].pos] = l;
	        DeQueue(q);
			if(q.n == 0 && l <= arr[j])
		    {
				l = arr[j];
		    }
	    }
		for(;l == arr[j];j++)
		{
			Insert(q, GetTNode(bur[j], j, prior[j]));
		}
		l++;
    }
	while(q.n != 0);
	for(i = 0;i < n;i++) 
	{ 
		tat[i] = finish[i] - arr[i];
		wt[i] = tat[i] - bur[i];
	} 
	printf("\nPName     Arrtime     Exectime    Waittime     TAT   Finish");
	for(int i=0;i<n;i++) 
	{ 
		printf("\n%d\t%6d\t\t%6d\t%6d\t%6d\t%6d%s", pn[i], arr[i], bur[i], wt[i], tat[i], finish[i], i == n-1 ? "\n":""); 
	    totwt += wt[i]; 
		tottat += tat[i]; 
	}
	printf("\nAverage waiting time    Average turnaround time");
	printf("\n%6.2f\t%6.2f",(float)totwt/n,(float)tottat/n);
}
