#include <stdio.h>
#include <time.h>

/* BU KOD ''INPUT.TXT'' ISIMLI, ICERISINDE KARISIK DUZENDE TAM SAYILARIN OLDU DOSYADAKI 6000 ADET VERIYI BUBBLE SORT, SELECTION SORT,
INSERTION SORT VE SHELL SORT SIRALAMA ALGORITMALARINA GORE KUCUKTEN BUYUGE SIRALAYABILMEKTEDIR
*/
void BubbleSort(int arr[],int size){
	int i,j;
	
	for(i=0;i<size;i++){
		for(j=1;j<size;j++){
			if(arr[j-1]>arr[j]){
				int temp=arr[j];
				arr[j] = arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
	for (i=0 ; i<size ; i++){ 
	printf("The number %d is: %i\n", i+1, arr[i]);
	}
	printf("\n\nBUBBLE SORT");
}

void SelectionSort(int arr[],int size){
	int i,j;
	int minindex;
	for(i=0;i<size;i++){
		minindex=i;
		for(j=i;j<size;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		int temp = arr[i];
		arr[i]=arr[minindex];
		arr[minindex]=temp;
	}
	for (i=0 ; i<size ; i++){
	printf("The number %d is: %i\n", i+1, arr[i]);
	}
	printf("\n\nKARISIK SIRALI SELECTION SORT"); 
}

void InsertionSort(int arr[],int size){
	int i,j;
	int element;
	
	for(i=1;i<size;i++){
		element = arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>element){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1] = element;
	}
	for (i=0 ; i<size ; i++){ 
		printf("The number %d is: %i\n", i+1, arr[i]);
	}
	printf("\n\nINSERTION SORT");
}

void ShellSort(int arr[], int size){
    int i, j, k, tmp;
    for (i = size / 2; i > 0; i = i / 2)
    {
        for (j = i; j < size; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
    for (i=0 ; i<size ; i++){ 
		printf("The number %d is: %i\n", i+1, arr[i]);
	}
	printf("\n\nSHELL SORT");
}

int main(void){
	
	double time_spent = 0.0; // PROGRAMIN CALISMA SURESINI HESAPLAMAK ICIN 92. 93. 111. VE 112. SIRADAKI KODLAR EKLENMISTIR
	clock_t begin = clock();
	
    FILE *file = fopen("input.txt", "r");
    int integers[6000];

    int i=0;
    int num;
    while(fscanf(file, "%d", &num) > 0) {
        integers[i] = num;
        i++;
    }
    fclose(file);

    //SelectionSort(integers,6000);
    //BubbleSort(integers,6000);
    //InsertionSort(integers,6000);
    //ShellSort(integers,6000);
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", time_spent);
  return 0;
}
