
/*Programma MergeSort*/

#include <iostream>

using namespace std;

void merge(int [],int,int,int);
void merge_sort(int[],int, int);

//Questa procedura implementa il mergeSort (per interi)

void merge_sort(int a[],int low,int high){
    int mid;
    if(low<high) {
        mid = low + (high-low)/2; //This avoids overflow when low, high are too large
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


void merge(int a[],int low,int mid,int high){
//low: indice piu` piccolo dell'array da fondere
//mid: mezzo dell'array da fondere
//high: indice piu` grande dell'array da fondere

    int h,i,j,k;
    int b[50]; //Abbiamo bisogno di un vettore di appoggio dove copiare i dati
    h=low; //Indice libero per scandire vettore di sinistra
    i=low; //Indica la prima posizione libera dell'array in cui stiamo copiando i dati
    j=mid+1; //Indice libero per scandire vettore di destra

    while((h<=mid)&&(j<=high)){ //Mentre non hai esaurito uno dei due sottovettori
        if(a[h]<=a[j]){
            b[i]=a[h];
            h++; //Avanza di uno con l'indice libero dell'array di sinistra
        }
        else{
            b[i]=a[j];
            j++; //Avanza di uno con l'indice libero dell'array di destra
        }
        i++; //
    }

    if(h>mid){ //Se hai esaurito il sottovettore di sinistra, riversa in b quanto rimane del sottovettore di destra
        for(k=j;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){ //Se hai esaurito il sottovettore di destra, riversa in b quanto rimane del sottovettore di sinistra
            b[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++) a[k]=b[k]; //Ricopia in a il vettore ordinato b. Questo passo si puo` ottimizzare usando vettori allocati dinamicamente.
}

int main()
{
    int num,i;

    
    int a[50];

    cout<<"********************************************************************************"<<endl;
    cout<<"                             MERGE SORT PROGRAM "<<endl;

    cout<<"******************************************************************* *************"<<endl;
    cout<<endl<<endl;
    cout<<"Please Enter THE NUMBER OF ELEMENTS you want to sort:"<<endl;
    cin>>num;
    cout<<endl;
    cout<<"Now, Please Enter the ( "<< num <<" ) numbers (ELEMENTS):"<<endl;
    for(i=0;i<num;i++){
        cin>>a[i] ;
    }
    
    merge_sort(a,0,num-1); //Chiamo mergesort passando l'indice minimo e massimo del vettore.
    
    cout<<endl;
    
    cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
    
    cout<<endl<<endl;

    for(i=0;i<num;i++)
        cout<<a[i]<< endl;

    cout<<endl<<endl<<endl<<endl;
    return 0;

}
