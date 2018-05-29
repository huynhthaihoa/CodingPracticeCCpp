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

bool isUniqueChars(char *str)
{
	int checker = 0;
	size_t len = strlen(str);
	int val = -1;
	for(size_t i = 0; i < len; ++i)
	{
		val = str[i] - 'a';
		if ((checker & (1 << val)) > 0) 
			return false;
		checker |= (1 << val);
	}
	return true;
}

int commonCharacterCount(std::string s1, std::string s2)
{
	std::map<char, int[2]> charactermaps;
	int count = 0;
	for(char& c : s1) 
	{
		try
		{
			++charactermaps.at(c)[0];
		}
		catch(out_of_range &e)
		{
			charactermaps[c] = {0, 0};
		}
	}
	for(char& c : s2) 
	{
		try
		{
			++charactermaps.at(c)[1];
		}
		catch(out_of_range &e)
		{
			charactermaps[c] = {0, 0};
		}
	}
	for(const auto &pair: charactermaps)
	{
		count += (pair.second[0] < pair.second[1]) ? pair.second[0] : pair.second[1];
	}
	return count;
}

bool isAlmostIncreasing(vector<int> v)
{
	bool hasRemovableEle = false;
    int size = v.size();
    for(int i = 0; i < size - 1; ++i)
    {
    	if(a[i + 1] <= a[i])
    	{
    		if(hasRemovable || (i < size - 2 && a[i + 2] <= a[i]))
    			return false;
    		hasRemovable = true;
    	}
    }
    return true;
}
// Input : str = "geeekk"
// Output : e

// Input : str = "aaaabbcbbb"
// Output : a

char getMaxConceChar(std::string a)
{
	int pivot;
	int count;
	int max_pivot;		
	int max_count = 0; 
	int size = a.length();
	for(int i = 0; i < size; ++i)
	{
		if(i == 0 || a[i] != a[pivot])
		{
			if(count > max_count)
			{
				max_count = count;
				max_pivot = pivot;
			}
			pivot = i;
			count = 1;
		}
		else if(a[i] == a[pivot])
			++count;
	}
	return a[max_pivot];
}
int Bit1Count(int number)
{
	int count = 0;
	while(number != 0) //number ^ 0 //number | 0
	{
		count += number & 1;
		number >>= 1;
	}
	return count;
}
bool isPalindrome(std::string str)
{
	size_t len = str.size();
	size_t half_of_len = len >> 1;
	--len;
	for(int i = 0; i < half_of_len; ++i)
	{
		if(str[i] != str[len - i])
			return false;
	}
	return true;
}
std::string LongestCommonPalindrome(std::string a, std::string b)
{
	size_t len = 2;
	size_t len_a = a.size();
	size_t len_b = b.size();
	size_t j;
	std::string test_str;
	std::string res_str = "";
	for(size_t i = 0; i + len < len_a + 1 && len <= len_b; ++i)
	{
		j = len;
		while(j <= len_a - i && j <= len_b)
		{
			test_str = a.substr(i, j);
			if(isPalindrome(test_str) && b.find(test_str)!= string::npos)
			{
				len = j;
				res_str = test_str;
			}
			j++;
		}
	}
	return res_str;
}
typedef struct Node
{
	Node* Next;
	Node* Prev;
	int info;
};
typedef Node* pNode
typedef struct List
{
	pNode Head;
	pNode Tail;
};
void subTranverse(List &l, int src, int des)
{
	pNode preSrcNode = nullptr;
	pNode srcNode = nullptr;
	pNode postDesNode = nullptr;
	pNode desNode = nullptr;
	pNode pTmp = nullptr;
	pNode pIter = l.head;
	int itr = 0;
	while(pIter != nullptr)
	{
		if(itr == src - 1)
		{
			preSrcNode = pIter;
			srcNode = pIter->Next;
		}
		else if(iter > src && iter < des)
		{
			pTmp = pIter->next;
			pIter->next = pIter->prev;
			pIter->prev = pTmp;
		}
		else if(iter == des)
		{
			desNode = pIter;
			postDesNode = desNode->Next;
			desNode->Next = desNode->Prev;//
			preSrcNode->Next = desNode;//
			desNode->Prev = preSrcNode;//
			srcNode->Next = postDesNode;//
			postDesNode->Prev = srcNode;//
		}
		else if(iter > des)
			break;
		itr++;
		if(iter > src && iter < des)
			pIter = pIter->Prev;
		else
			pIter = pIter->Next;
	}
}