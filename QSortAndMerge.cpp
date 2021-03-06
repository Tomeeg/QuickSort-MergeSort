#include "stdafx.h"
#include <iostream>

int Partition(int* tab, int l, int r)
{
	int x = tab[l];
	int l_m = l - 1;
	int r_m = r + 1;
	int temp;
	while (true)
	{
		l_m = l_m + 1;
		if (tab[l_m] >= x)
			break;
	}
	while (true)
	{
		r_m = r_m - 1;
		if (tab[r_m] <= x)
			break;
	}
	if (l_m < r_m)
	{
		temp = tab[l_m];
		tab[l_m] = tab[r_m];
		tab[r_m] = temp;
	}
	else
		return r_m;
}

void QuickSort(int* tab, int p, int r)
{
	if (p < r)
	{
		int q = Partition(tab, p, r);
		QuickSort(tab, p, q);
		QuickSort(tab, q + 1, r);
	}
}

void merge(int* tab, int n, int pocz, int sr, int kon)
{
	int i, j, q;
	int* t = (int*)malloc(n * sizeof(int));
	for (i = pocz; i <= kon; i++)
		t[i] = tab[i];
	i = pocz;
	j = sr + 1;
	q = pocz;
	while (i <= sr && j <= kon) {
		if (t[i]<t[j])
			tab[q++] = t[i++];
		else
			tab[q++] = t[j++];
	}
	while (i <= sr) tab[q++] = t[i++]; 
	free(t);
}

void mergesort(int* tab, int n, int pocz, int kon)
{
	int sr;
	if (pocz<kon) {
		sr = (pocz + kon) / 2;
		mergesort(tab, n, pocz, sr);
		mergesort(tab, n, sr + 1, kon);
		merge(tab, n, pocz, sr, kon);
	}
}

int main()
{
	int n;
	int *tablica;
	scanf_s("%d", &n);
	tablica = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &tablica[i]);
	}
	//QuickSort(tablica, 0, n-1);
	mergesort(tablica, n, 0, n - 1);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", tablica[i]);
	}
	free(tablica);
    return 0;
}

