int kiemtra(int n)
{
	int chusotruoc = 10;
	int chusoke = 0;
	while (n > 0)
	{
		chusoke = n % 10;
		if(chusotruoc < chusoke)
			return false;
		chusotruoc = chusoke;
		n /= 10;
	}
	return true;
}
bool IsMonotonic(const long &n)
{
	if(n < 100)
		return true;
	int check = (n % 10 > (n % 100 - n % 10) / 10) ? 1 : -1;
	do
	{
			n /= 10;
			if((n % 10 - (n % 100 - n % 10) / 10) * check < 0)
				return false;
	}
	while(n > 0);
	return true;
}
bool RemoveElement(int a[], int &n, int &pos)
{
	if(pos < 0 || pos >= n)
		return false;
	for(int i = pos; i < n - 1; i++)
		a[i] = a[i + 1];
	pos--;
	n--;
	return true;
}
void PrintRepeatNumber(int a[], int n)
{
	int count; //đếm số lần xuất hiện của 1 phần tử trong mảng
	for(int i = 0; i < n - 1; i++)
	{
		count = 1;	
		for (int j = i + 1; j < n; j++)
		{
			if(a[j] == a[i])
			{
				count++; 
				RemoveElement(a, n, j); //xóa các phần tử trùng với a[i]
			}
		}
		if(count == 2)	//có 1 phần tử trùng với a[i] hay a[i] xuất hiện 2 lần (nếu kiểm tra a[i] xuất hiện 3 lần thì đk count == 3)
			printf("%d ",a[i]);
	}
}
int CountRepeatNumber(vector<int> a, int n)
{
	int count = 0;
	int repeat_count = 0;
	for(int i = 0; i < n - 1; i++)
	{
		count = 0;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] == a[i])
			{
				count++;
				a.erase(a.begin() + j);
				j--;
			}
		}
		if(count)
			repeat_count++;
	}
	return repeat_count;
}
int CountUniqueValue(int a[], int n)
{
	bool flag;
	for(int i = 0; i < n; i++)
	{
		flag = false;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] == a[i])
				flag = RemoveElement(a, n, j);
		}
		if(flag)
			flag = !RemoveElement(a, n, i);
	}
	return n;
}
{
	int _size = values.size();
    int account = 0;
    int j = -1;
    vector<int> mlist;
    for(int start = 0; start < _size; start++)
    {
        account = 0;
        j = i;
        do
        {
            account += values[j];
            j++;
			if(j >= _size)
				j -= _size;
        }
		while(account > 0 && j != i);
        if(j == start)
            mlist.push_back(start);
    }
    return mlist;
}


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int MaxCount(string a, string b, int indexA = 0, int indexB = 0)
{
    int max = 0;
	int lenA = a.length();
	int lenB = b.length();
    int count;
    int j;
    int k;
    for(int i = indexA; i < lenA; i++)
    {
        count = 0;
        j = b.find_first_of(a[i], indexB);
        if(j != string::npos)
		{
			if(i < lenA - 1 && j < lenB - 1)
				count = 1 + MaxCount(a, b, i + 1, j + 1);
			else
				count = 1;
		}
        if(count > max)
            max = count;
    }
    return max;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string a, b;
    cin >> a >> b;
    cout << MaxCount(a, b);
    return 0;
}
int MaxCount(const string &a, const string &b)
{
    int max = 0;
    int count;
    int lenA = a.length();
    int lenB = b.length();
    int k, l;
    for(int i = 0; i < lenA; i++)
    {
        k = count = 0;
        for(int j = i; j < lenA; j++)
        {
            l = b.find_first_of(a[j], k);
            if(l != string::npos)
            {
				count++;
                if(l < lenB - 1)
                    k = l + 1;
				else
					break;
            }
        }
        if(count > max)
            max = count;
    }
    return max;
}

void sort(vector<int> &a)//sort để 2 ở đầu, 0 ở giữa, 1 ở cuối
{
	int n = a.size();
	int i = 0;
	int j = n - 1;
	for(int k = 0; k < n; k++)
	{
		if(a[k] == 2)
		{
			while(a[i] == 2)
		       i++;
			if(k > i)	//neu k khac i thi day a[k] vao vi tri i
				swap(a[k], a[i]);
			i++;
		}
		if(a[k] == 1)
		{
			while(a[j] == 1)
		       j--;
			if(k < j)	//neu k khac j thi day a[k] vao vi tri j
				swap(a[k], a[j]);
			j--;
		}
	}
}

int DemSoNutTheoBac(Tree T, int bac)//quy ước: count là so node con cua T, child[count] la danh sach node con
{
	if(!T)
		return 0;
	if(bac == 0)
		return 1;
	int count = 0;
	for(int i = 0; i < T->count; i++)
		count += DemSoNutTheoBac(T->child[i], bac - 1);
	return count;
}

void XuatNutTheoBac(Tree T, int bac)
{
	if(!T)
		return;
	if(bac == 0)
	{
		cout << T->key << " ";
		return;
	}
	for(int i = 0; i < T->count; i++)
		XuatNutTheoBac(T->child[i], bac - 1);
}

int DemSoNutNhoHonBac(Tree T, int bac)
{
	if(!T || bac == 0)
		return 0;
	int count = 1;
	for(int i = 0; i < T->count; i++)
		count += DemSoNutNhoHonBac(T->child[i], bac - 1);
	return count;
}

int DemSoNutLonHonBac(Tree T, int bac)
{
	if(!T)
		return 0;
	
}

int DemSoNutNhoHonHoacBangBac(Tree T, int bac)
{
	if(!T || bac == -1)
		return 0;
	int count = 1;
	for(int i = 0; i < T->count; i++)
		count += DemSoNutNhoHonHoacBangBac(T->child[i], bac - 1);
	return count;
}	

void separatestring(string s, vector<string> &v)
{
	int len = s.len();
	int start = 0;
	int end = 0;
	for(int i = 1; i < len; i++)
	{
		if(s[i] == s[start])
			end++;
		else
		{
			v.push_back(s.substr(start, end - start + 1));
			start = end = i;
		}
	}
	v.push_back(s.substr(start, end - start + 1));
}



bool isUniqueValue(int a[], int n)
{
	std::map<int, int> mymap;
	for(int i = 0; i < n; ++i)
	{
		try
		{
			++mymap.at(a[i]);
			return false;
		}
		catch(const std::out_of_range& oor)
		{
			mymap[a[i]] = 0;
		}
	}
	return true;
}

