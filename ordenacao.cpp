#include<iostream>
#include<cstdlib>
#include<time.h>
#include<stdio.h>

using namespace std;

void selection_sort(int *elementos, int n){
    int min_index, temp;
	for(int i =0; i <n-1; i++)
	{
		min_index = i;
		for (int j = i+1; j <= n-1; j++)
		{
			if(elementos[min_index] > elementos[j]){
				min_index = j;
			}
		}
		
		temp = elementos[i];
		elementos[i] = elementos[min_index];
		elementos[min_index] = temp;
	}
}

void insertion_sort(int *elementos, int n){
    int j, x;
	for(int i =1; i <n; i++)
	{
		j =i-1;
		x = elementos[i];
		while( x < elementos[j] && j>=0)
		{
			elementos[j+1] = elementos[j];
			elementos[j] = x;
			j--;
		}
	}
}

void shell_sort(int *elementos, int n){
	int h=1, j, x;
	do{ h =3 * h + 1; } while (h< n);
	do{
		h /=3;
		for(int i = h ; i < n;  i++)
		{
			x = elementos[i];
			j = i;
			while (j >= h && x < elementos[j - h]) {
                elementos[j] = elementos[j - h];
                j = j - h;
            }
            elementos[j] = x;
		}
	}while( h > 1 );
}

void Juntar(int vetor[], int ini, int meio, int fim, int vetAux[]) {
    int esq = ini;
    int dir = meio;
    for (int i = ini; i < fim; ++i) {
        if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i] = vetor[dir];
            ++dir;
        }
    }
    //copiando o vetor de volta
    for (int i = ini; i < fim; ++i) {
        vetor[i] = vetAux[i];
    }
}

void MergeSort(int vetor[], int inicio, int fim, int vetorAux[]) {
    if ((fim - inicio) < 2) return;
    
    int meio = ((inicio + fim)/2);
    MergeSort(vetor, inicio, meio, vetorAux);
    MergeSort(vetor, meio, fim, vetorAux);
    Juntar(vetor, inicio, meio, fim, vetorAux);
}

void merge_sort(int vetor[], int tamanho) {
    int vetorAux[tamanho];
    MergeSort(vetor, 0, tamanho, vetorAux);
}

void quick_sort(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[(began + end) / 2];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quick_sort(values, began, j+1);
	if(i < end)
		quick_sort(values, i, end);
}

int mediana(int n){
    int x[3];
    srand(time(NULL));
    x[0] = rand()%n;
    x[1] = rand()%n;
    x[2] = rand()%n;
    insertion_sort(x,3);
    return x[1];
}

void quick_sort_mediana(int values[], int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = values[mediana(end)];
	while(i <= j)
	{
		while(values[i] < pivo && i < end)
		{
			i++;
		}
		while(values[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = values[i];
			values[i] = values[j];
			values[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quick_sort_mediana(values, began, j+1);
	if(i < end)
		quick_sort_mediana(values, i, end);
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heap_sort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void ler_arquivo(int *vet, int tam){
	FILE *arq;
	arq = fopen("entrada1e+06.txt","r");
	for(int i = 0; i < tam; i++){
		fscanf(arq,"%d",&vet[i]);
	}
	fclose(arq);
}

void cria_crescente(int *vet, int tam){
	for(int i = 0; i < tam; i++){
		vet[i] = i+1;
	}
}

void cria_decrescente(int *vet, int tam){
	for(int i = tam-1; i >= 0; i--){
		vet[i] = tam-i;
	}
}

int main(){
    int n = 10, *el = new int[10000000];
	int tipo = 1;
    clock_t Ticks[2];

	//SELECTION SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			selection_sort(el,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - SELECTION SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//INSERTION SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			insertion_sort(el,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - INSERTION SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//SHEL SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			shell_sort(el,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - SHELL SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//MERGE SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			merge_sort(el,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - MERGE SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//HEAP SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			heap_sort(el,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - HEAP SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//QUICK SORT
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			quick_sort(el,0,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - QUICK SORT ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}
	n = 10;

	//QUICK SORT - MEDIANA
	for(int j = 0; j < 5; j++){
		cout << "Tamanho da entrada: " << n << endl;
		for(int i = 1; i < 11; i++){
			
			if(tipo == 1)
				ler_arquivo(el,n);
			else if(tipo == 2)
				cria_crescente(el,n);
			else
				cria_decrescente(el,n);

			Ticks[0] = clock();
			quick_sort_mediana(el,0,n);
			Ticks[1] = clock();

			cout << "Teste " << i << " - QUICK SORT MEDIANA ";
			cout << "Tempo gasto: " << (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC << " em ms" << endl;
			cout << endl;
		}
		if(j == 0)
			n*=100;
		else
			n*=10;
	}

	delete [] el;
    return 0;
}