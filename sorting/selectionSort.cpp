#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
     for(int i=0;i<=n-2;i++){
        int smallest = i;
        for(int j = i+1;j<=n-1;j++){

            if(a[j]<a[smallest]){
                smallest = j;
            }
        }

        //swap(a[i],a[smallest]);
        int temp = a[i];   // Step 1: Store a[i] in a temporary variable
        a[i] = a[smallest]; // Step 2: Assign a[smallest] to a[i]
        a[smallest] = temp; // Step 3: Assign temp (which holds a[i]) to a[smallest]

     }
}

int main(){

   int n;
   cin>>n;

   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }

   selectionSort(a,n);

   for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
   }

    return 0;
}
