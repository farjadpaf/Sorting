#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class CountingSort{
public:

    void CountinSort(int arr[] , int length , int first , int last){ // Range =  first to last (first and last included)

       
        int range =  (last - first) + 1  ;
        int *temp = new int[range]{0} ;
        int *output = new int[length] ;

        if(length > 1){
        //calculting how many times a number appreared in the array and storing it in the temp array
            for(int i = 0 ; i < length ; ++i){
            int value = arr[i];
            ++temp[value-first] ;
        }
        //calculting camulative frequncy
        for(int j =1 ; j < range ; ++ j){
            temp[j]+=temp[j-1];
        }

        for(int k = length-1 ; k >= 0 ; --k){
            int value = arr[k] ;
            int count_indx = value - first ;
            int postion = temp[count_indx]-1 ;

            output[postion] = value ;
            temp[count_indx]-- ;

        }


        for(int h = 0 ; h< length ; ++ h){
            arr[h] = output[h];
        }

        delete[] output ;
        delete[] temp ;
        cout<<"<---Array sorted successfuly---> \n" ;




        }
   
    }


    void print(int arr[], int length ){
        cout<<"->Counting Sort : " ;

        for(int x =0 ;  x < length ; ++ x){
            cout<< arr[x] << " " ;
            
        }cout<<endl;
    }

};



class RadixSort{
private :
    int maxvalue(int arr[] , int length){
        int max = arr[0] ;
        if(length>1){
            for(int i = 1 ; i< length ; ++i){
            if(arr[i] > max){
                max = arr[i] ;
            }
        }
        }return max ;
    }

    //counting sort for the redix sort
    void countingSort(int arr[] , int exp , int length){
     
        int count[10] = {0};
        int *output = new int[length] ;


        for(int i = 0 ; i < length ; ++i){
            count[(arr[i]/exp)%10]++ ;

        }

        for(int j = 1 ; j < 10 ; ++ j){
            count[j]+= count[j-1] ;
        }

        for(int k = length -1 ; k >= 0 ; --k){
            int count_indx = (arr[k]/exp)%10 ;

            int pos = count[count_indx] - 1 ;

            output[pos] = arr[k] ;

            count[count_indx]-- ;
        }


        for(int t = 0 ; t < length ; ++t){
            arr[t] = output[t];
        }

        //freeing memory
        delete[] output ;

    }

public:
    void redixSort(int arr[], int length){

        int max = maxvalue(arr,length) ;

        for(int exp = 1 ; max/exp > 0 ; exp *= 10){
            countingSort(arr , exp , length);

        }
    }


    void printRadixSort(int arr[] , int length){
        cout<<"->Radix Sort : " ;
        for(int i = 0 ; i < length ; ++i){

            cout<<arr[i]<<" " ;
        }
        cout<<endl ;
    }


};



class PigeonholeSort {
public:
    void pigeonholeSort(int arr[], int n) {
        int min = arr[0];
        int max = arr[0];

        //Find min and max
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }

        int range = max - min + 1;

        //Create pigeonholes
        int* holes = new int[range]();

        //Fill the holes
        for (int i = 0; i < n; i++) {
            holes[arr[i] - min]++;
        }

        //Put elements back into array
        int index = 0;
        for (int i = 0; i < range; i++) {
            while (holes[i]-- > 0) {
                arr[index++] = i + min;
            }
        }

        delete[] holes;
    }

    void printArray(int arr[], int n) {
        cout<<"->PigeonHole Sort : ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << ", ";
        cout << endl;
    }
};


class BeadSort {
public:
    void beadSort(int arr[], int n) {
        if (n <= 1) return;

        //Find the maximum value
        int maxVal = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > maxVal) maxVal = arr[i];

        //Create bead structure
        bool** beads = new bool*[n];
        for (int i = 0; i < n; i++) {
            beads[i] = new bool[maxVal]{false};
            for (int j = 0; j < arr[i]; j++)
                beads[i][j] = true;
        }

        //Let beads "fall" under gravity
        for (int j = 0; j < maxVal; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (beads[i][j]) sum++;
                beads[i][j] = false;
            }
            for (int i = n - sum; i < n; i++)
                beads[i][j] = true;
        }

        // Read sorted values
        for (int i = 0; i < n; i++) {
            int count = 0;
            while (count < maxVal && beads[i][count]) count++;
            arr[i] = count;
        }

        
        for (int i = 0; i < n; i++) delete[] beads[i];
        delete[] beads;
    }

    void printArray(int arr[], int n) {
        cout << "->Bead Sort: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
};



int main() {
    int originalArr[] = {29, 10, 14, 37, 13, 25, 7, 3};
    const int n = sizeof(originalArr)/sizeof(originalArr[0]);

    // Make copies for each sort (sorting is in-place)
    int arr1[n], arr2[n], arr3[n], arr4[n];
    for(int i=0;i<n;i++){
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = originalArr[i];
    }

    cout<<"====================================================="<<endl;

    // Counting Sort
    CountingSort cs;
    cs.CountinSort(arr1, n, 3, 37); // Range = 3 to 37
    cs.print(arr1, n);

    // Radix Sort
    RadixSort rs;
    rs.redixSort(arr2, n);
    rs.printRadixSort(arr2, n);

    // Pigeonhole Sort
    PigeonholeSort ph;
    ph.pigeonholeSort(arr3, n);
    ph.printArray(arr3, n);

    // Bead Sort
    BeadSort bs;
    bs.beadSort(arr4, n);
    bs.printArray(arr4, n);

    return 0;
}