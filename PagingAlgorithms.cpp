#include<stdio.h>
#include<Windows.h>

int n;//so phan tu can tham chieu
int a[100];//chuoi tham chieu
int frame;//so khung trang
int frames[10];//chuoi khung trang
int max_value(int frs[10], int fr)
{
	int index = 0,i;
	for(i = 0; i < fr; ++i)
	{
		if(frs[i] > frs[index])
			index = i;
	}
	return index;
}
int count(int victim, int src[100], int length)//vi tri bat dau tim:victim
{
	int tmp = 0, i;
	for(i = victim + 1; i < length; ++i)
	{
		tmp++;
		if(src[i] == src[victim])
			break;
	}
	if(i == length)
		return length + 1;
	return tmp;
}
void FIFO()
{
	int available = 0, k, i, j;
	for(i = 0; i < frame; ++i)
		frames[i]= -1; 
	j = 0;
	printf("\t|Chuoi|\t|Khung trang");
	for(k = 0; k < frame - 1; ++k)
		printf("\t");
	printf("|\n");
	for(i = 0; i < n; ++i)
	{
		printf("\t| %d |\t", a[i]);
		available = 0; 
		for(k = 0; k < frame; ++k)
		{
			if(frames[k] == a[i])
			{
				available = 1; 
				break;
			}
		}
		if (available == 0) 
		{
			frames[j] = a[i];
			j=(j + 1) % frame;
			printf("|");
			for(k = 0; k < frame; ++k)
				printf("%d\t", frames[k]);
			printf("| *"); 
		}
		else
		{
			printf("|");
			for(k = 0; k < frame; ++k)
				printf("%d\t", frames[k]);
			printf("|");
		}
		printf("\n");
	}
}
void OPT()
{
	int available = 0, k, i, index = -1;
	int candidate[10];
	for(i = 0; i < frame; ++i)
	{
		frames[i]= -1;
		candidate[i] = n + 1;
	}
	printf("\t|Chuoi|\t|Khung trang");
	for(k = 0; k < frame - 1; ++k)
		printf("\t");
	printf("|\n");
	for(i = 0; i < n; ++i)
	{
		printf("\t| %d |\t",a[i]);
		available = 0;
		for(k = 0; k < frame; ++k)
		{
			if(frames[k] == a[i])//co frames bang a[i]
			{
				available = 1;
				break;
			}
		}
		if(available == 1)//co frames bang a[i],khong can thay the
		{
			for(int j = 0; j < frame; ++j)
			{
				if(frames[j] == a[i])
					candidate[j] = count(i, a, n);
				else if(frames[j] < n + 1)
					candidate[j]--;
			}
			printf("|");
			for(k = 0; k < frame; ++k)
				printf("%d\t", frames[k]);
			printf("|");
		}
		else //if(available == 0)//khong co frames nao bang a[i],thuc hien thay the
		{
			//chon ra frames co candidate lon nhat de thuc hien thay the
			printf("|");
			index = max_value(candidate, frame);
			for(k = 0; k < frame; ++k)
			{
				if(k == index)
				{
					candidate[k] = count(i, a, n);
					frames[k] = a[i];
				}
				else if(candidate[k] < n + 1)
					candidate[k]--;
			}
			for(k = 0; k < frame; ++k)
				printf("%d\t", frames[k]);
			printf("|*");
		}
		printf("\n");
	}
}
void LRU()
{
	int available = 0, k, i;
	int candidate[10];
	for(i = 0; i < frame; ++i)
	{
		frames[i]= -1;
		candidate[i] = n + 1;
	}
	printf("\t|Chuoi|\t|Khung trang");
	for(k = 0; k < frame - 1; ++k)
		printf("\t");
	printf("|\n");
	for(i = 0; i < n; ++i)
	{
		printf("\t| %d |\t",a[i]);
		available = 0;
		for(k = 0; k < frame; ++k)
		{
			if(frames[k] == a[i])//co frames bang a[i]
			{
				available = 1;
				break;
			}
		}
		if(available == 1)//co frames bang a[i],khong can thay the
		{
			for(int j = 0; j < frame; ++j)
			{
				if(frames[j] != a[i] && candidate[j] < n + 1)//tang candidate doi voi cac frame khong trung a[i]
					candidate[j]++; 
				else if (frames[j] == a[i])
					candidate[j] = 0;//cap nhat lai candidate doi voi frame trung a[i]
			}
			printf("|");
			for(k = 0; k < frame; ++k)
				printf("%d\t", frames[k]);
			printf("|");
		}
		else //if(available == 0)//khong co frames nao bang a[i],thuc hien thay the
		{
			//chon ra frames co candidate lon nhat de thuc hien thay the
			printf("|");
			int index = max_value(candidate, frame);
			for(k = 0; k < frame; ++k)
			{
				if(k == index)
				{
					candidate[k] = 0;
					frames[k] = a[i];
				}
				else if(candidate[k] < n + 1)
					candidate[k]++;
			}
			for(k = 0; k < frame; ++k)
				printf("%d\t",frames[k]);
			printf("|*");
		}
		printf("\n");
	}
}
int main()
{
	int select;
	printf("-----Page Replacement algorithm-----\n");
	printf("1.Chuoi tham chieu mac dinh\n");
	printf("2.Nhap chuoi tham chieu bang tay\n");
	scanf("%d",&select);
	do
	{
	switch(select)
	{
		case 1:
			{
				n = rand() % 15 + 5;
				printf("So phan tu can tham chieu:%d\n", n);
				break;
			}
		case 2:
			{
				printf("Nhap so phan tu can tham chieu:");
				scanf("%d", &n);
				printf("Nhap chuoi can tham chieu:\n");
				for(int i = 0; i < n; ++i)
				{
					printf("Nhap phan tu thu %d:",i+1);
					scanf("%d", &a[i]);
				}
				break;
			}
		default:
			{
				printf("Nhap khong hop le, yeu cau nhap lai\n");
				break;
			}
	}
	}
	while(select != 1 && select != 2);
	printf("Chuoi can tham chieu:\n");
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
		printf("Phan tu thu %d:%d\n", i + 1, a[i]);
	}
	printf("-----Page Replacement algorithm-----\n");
	printf("Nhap so khung trang\n");
	scanf("%d", &frame);
	printf("-----Page Replacement algorithm-----\n");
	printf("1.Giai thuat FIFO\n");
	printf("2.Giai thuat OPT(Optimal)\n");
	printf("3.Giai thuat LRU\n");
	scanf("%d", &select);
	do
	{
	switch(select)
	{
		case 1:
			{
				FIFO();
				break;
			}
		case 2:
			{
				OPT();
				break;
			}
		case 3:
			{
				LRU();
				break;
			}
		default:
			{
				printf("Nhap khong hop le, yeu cau nhap lai\n");
				break;
			}
	}
	}
	while(select < 1 || select > 3);
	system("Pause");
}
