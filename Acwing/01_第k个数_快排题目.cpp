/*
* 
AcWing786. 第k个数
一、题目描述
		给定一个长度为 n的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序 后的第 k个数。
输入格式
		第一行包含两个整数 n 和 k。
		第二行包含 n个整数（所有整数均在 1∼109范围内），表示整数数列。
输出格式
		输出一个整数，表示数列的第 k小数。
数据范围
		1≤n≤100000,	1≤k≤n

输入样例：
		5 3
		2 4 1 5 3
输出样例：
		3
*/

#include <iostream>
using namespace std;
const int N = 10010;
int n, k;
int q[N];

void quick_sort(int q[], int l, int r, int k)
{
	if (l >= r) return;
	int i = l - 1, j = r + 1, x = q[(l + r) >> 1];

	while (i < j)
	{
		do i++;
		while (q[i] < x);
		
		do j--;
		while (q[j] > x);

		if (i < j)
			swap(q[i], q[j]);
	}
	//记录左边的长度
	int len = j - l + 1;
	
	quick_sort(q, l, j, k);
	quick_sort(q, j + 1, r, k - len);
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
	}
	
	quick_sort(q, 1, n, k);
	cout << q[k] << endl;
	
	system("pause");
	return 0;
}