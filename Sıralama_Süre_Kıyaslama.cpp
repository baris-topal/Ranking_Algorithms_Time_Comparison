#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

void takas(int* t1, int* t2)
{
	int temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

void BubbleSort(int dizi[], int n)
{
	int i, j;
	bool takasla;
	for (i = 0; i < n - 1; i++)
	{
		takasla = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (dizi[j] > dizi[j + 1])
			{
				takas(&dizi[j], &dizi[j + 1]);
				takasla = true;
			}
		}

		//Eğer İki Eleman İç Döngü Tarafından Değiştirilmemişse
		if (takasla == false)
			break;
	}
}

void SelectSort(int dizi[], int n)
{
	int i, j, min_idx;

	// Sıralanmamış alt dizinin tek tek hareket sınırı
	for (i = 0; i < n - 1; i++)
	{
		// Sıralanmamış dizideki minimum elemanı bulun 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (dizi[j] < dizi[min_idx])
				min_idx = j;

		// Bulunan minimum elemanı ilk elemanla değiştirin
		takas(&dizi[min_idx], &dizi[i]);
	}
}

void InsertSort(int dizi[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = dizi[i];
		j = i - 1;

		//Anahtardan daha büyük olan dizi elemanlarını mevcut konumlarının önündeki bir konuma taşıyın.
		while (j >= 0 && dizi[j] > key)
		{
			dizi[j + 1] = dizi[j];
			j = j - 1;
		}
		dizi[j + 1] = key;
	}
}

#pragma region MergeSort

void Merge(int dizi[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Geçici diziler oluşturma 
	int* L = new int[n1];
	int* R = new int[n2];

	// Verileri geçici dizlere kopyalama L[]-R[] 
	for (i = 0; i < n1; i++)
		L[i] = dizi[l + i];
	for (j = 0; j < n2; j++)
		R[j] = dizi[m + 1 + j];

	// Temp dizilerini birleştir dizi[l..r]
	i = 0; // İlk alt dizinin başlangıç dizini
	j = 0; // İkinci alt dizinin başlangıç dizini
	k = l; // Birleştirilmiş alt dizinin başlangıç dizini
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			dizi[k] = L[i];
			i++;
		}
		else
		{
			dizi[k] = R[j];
			j++;
		}
		k++;
	}

	// Varsa L[]'nin kalan öğelerini kopyalama
	while (i < n1)
	{
		dizi[k] = L[i];
		i++;
		k++;
	}

	// Varsa R[]'nin kalan öğelerini kopyalama
	while (j < n2)
	{
		dizi[k] = R[j];
		j++;
		k++;
	}
}

// Altdizinin dizisini sıralamak için L sol katsayıdır ve R katsayıdır

void MergeSort(int dizi[], int l, int r)
{
	if (l < r)
	{
		// (L+R)/2 ile aynıdır ancak L ve R'nin taşmasını önler
		int m = l + (r - l) / 2;

		// Birinci ve ikinci alt yarıları sırala
		MergeSort(dizi, l, m);
		MergeSort(dizi, m + 1, r);

		Merge(dizi, l, m, r);
	}
}

#pragma endregion

#pragma region QuickSort

/* Bu işlev son elemanı pivot olarak alır,
pivot elemanını sıralı dizide doğru pozisyona getirir
ve pivotun sağındaki tüm daha küçük (pivottan küçük)
ve tüm büyük elemanları pivotun sağına yerleştirir. */
int bölme(int dizi[], int low, int high)
{
	int pivot = dizi[high];    // pivot 
	int i = (low - 1);  // Daha küçük elemanın indeksi

	for (int j = low; j <= high - 1; j++)
	{
		// Mevcut eleman pivottan küçük veya eşitse
		if (dizi[j] <= pivot)
		{
			i++;    // küçük elemanın artış endeksi
			takas(&dizi[i], &dizi[j]);
		}
	}
	takas(&dizi[i + 1], &dizi[high]);
	return (i + 1);
}

/* QuickSort'u uygulayan Ana İşlev
dizi[] --> sıralanacak dizi,
low  --> başlangıç elemanı,
high  --> bitiş elemanı */
void QuickSort(int dizi[], int low, int high)
{
	if (low < high)
	{
		// Pi bölümleme dizinidir, dizi[p] şimdi doğru yerde  
		int pi = bölme(dizi, low, high);

		// Bölme öncesi ve bölüm sonrası öğeleri ayrı ayrı ayırma
		QuickSort(dizi, low, pi - 1);
		QuickSort(dizi, pi + 1, high);
	}
}

#pragma endregion

void DiziYaz(int dizi[], int n)
{
	for (int i = 0; i < n; i++)
		cout << dizi[i] << " ";
	cout << endl;
}

int main()
{
	int boyut, secim;
	char secim1;
	srand(time(0));
	do {
		system("cls");
		cout << "Dizinin boyutunu giriniz:";
		cin >> boyut;
		int* dizi1 = new int[boyut];
		int* dizi2 = new int[boyut];
		int* dizi3 = new int[boyut];
		int* dizi4 = new int[boyut];
		int* dizi5 = new int[boyut];
		for (int i = 0; i < boyut; i++)
		{

			dizi1[i] = (rand() % -100 - rand() % 100);
			dizi2[i] = dizi1[i];
			dizi3[i] = dizi1[i];
			dizi4[i] = dizi1[i];
			dizi5[i] = dizi1[i];
		}
		if (25 < boyut);
		else
		{
			cout << endl;
			cout << "Rastgele Dizi: ";
			DiziYaz(dizi1, boyut);
		}
		cout << "\nSiralamalar basladi\n\n";

		auto start_time = high_resolution_clock::now();
		BubbleSort(dizi1, boyut);
		auto end_time = high_resolution_clock::now();
		auto time = end_time - start_time;
		cout << "Bubble Sort: ";
		if (duration_cast<microseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniyede siraladi.\n\n";
		else if (duration_cast<milliseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede siraladi.\n\n";
		else if (duration_cast<seconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede / " << duration_cast<milliseconds>(time).count() << " millisaniyede siraladi.\n\n";
		else
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede / " << duration_cast<milliseconds>(time).count() << " millisaniye / " << duration_cast<seconds>(time).count() << " saniyede siraladi.\n\n";

		start_time = high_resolution_clock::now();
		SelectSort(dizi2, boyut);
		end_time = high_resolution_clock::now();
		time = end_time - start_time;
		cout << "Select Sort: ";
		if (duration_cast<microseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniyede siraladi.\n\n";
		else if (duration_cast<milliseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede siraladi.\n\n";
		else if (duration_cast<seconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniyede siraladi.\n\n";
		else
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniye / " << duration_cast<seconds>(time).count() << " saniyede siraladi.\n\n";

		start_time = high_resolution_clock::now();
		InsertSort(dizi3, boyut);
		end_time = high_resolution_clock::now();
		time = end_time - start_time;
		cout << "Insert Sort: ";
		if (duration_cast<microseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniyede siraladi.\n\n";
		else if (duration_cast<milliseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede siraladi.\n\n";
		else if (duration_cast<seconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniyede siraladi.\n\n";
		else
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniye / " << duration_cast<seconds>(time).count() << " saniyede siraladi.\n\n";

		start_time = high_resolution_clock::now();
		MergeSort(dizi4, 0, boyut - 1);
		end_time = high_resolution_clock::now();
		time = end_time - start_time;
		cout << "Merge Sort: ";
		if (duration_cast<microseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniyede siraladi.\n\n";
		else if (duration_cast<milliseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede siraladi.\n\n";
		else if (duration_cast<seconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniyede siraladi.\n\n";
		else
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniye / " << duration_cast<seconds>(time).count() << " saniyede siraladi.\n\n";

		start_time = high_resolution_clock::now();
		QuickSort(dizi5, 0, boyut - 1);
		end_time = high_resolution_clock::now();
		time = end_time - start_time;
		cout << "Quick Sort: ";
		if (duration_cast<microseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniyede siraladi.\n\n";
		else if (duration_cast<milliseconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniyede siraladi.\n\n";
		else if (duration_cast<seconds>(time).count() == 0)
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniyede siraladi.\n\n";
		else
			cout << duration_cast<nanoseconds>(time).count() << " nanosaniye / " << duration_cast<microseconds>(time).count() << " microsaniye / " << duration_cast<milliseconds>(time).count() << " millisaniye / " << duration_cast<seconds>(time).count() << " saniyede siraladi.\n\n";
		if (25 < boyut);
		else
		{
			cout << "Sirali Dizi: ";
			DiziYaz(dizi5, boyut);
			cout << endl;
		}
		cout << "Tekrar denemek istermisiniz(E/H)\nSecim:";
		cin >> secim1;
		cout << endl;
	} while (secim1 == 'e' | secim1 == 'E');
	exit(0);
	return 0;
}