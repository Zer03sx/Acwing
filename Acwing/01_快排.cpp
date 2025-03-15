#include <iostream>
using namespace std;

const int N = 100010;
int q[N];
int n;

void quick_sort(int q[], int l, int r)
{
	if (l >= r)
		return;
	int i = l - 1, j = r + 1;
	int x = q[(l + r) >> 1];

	while (l < r)
	{
		do i++;
		while (q[i] < x);
		
		do j--;
		while (q[j] > x);
		
		if (i < j)
			swap(q[i], q[j]);
	}
	quick_sort(q, l ,j);
	quick_sort(q, j + 1, r);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> q[i];
	
	quick_sort(q, 1, n);
	
	for (int i = 1; i <= n; i++)
		cout << q[i] << " ";
	cout << endl;
	
	system("pause");
	return 0;
}