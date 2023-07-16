#include<random>
#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

class analysis{

    int begin=0;
    int *dataSet;
    int limit, sort_tech, sort_ord;

    public:

    analysis(){
        cout<<"Enter limit of numbers: ";
        cin>>limit;
        dataSet = new int[limit];

        cout<<"\nSelect Sorting Case:\n";
        cout<<"1. Best\n";
        cout<<"2. Average\n";
        cout<<"3. Worst\n\n";
        cin>>sort_ord;

        cout<<"\nSelect Sorting Technique:\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Selection Sort\n";
        cout<<"3. Insertion Sort\n";
        cout<<"4. Merge Sort\n";
        cout<<"5. Quick Sort\n\n";
        cin>>sort_tech;
        
        assaign_data();
    }

    void assaign_data(){
        random_device seed;
        mt19937 generator(seed());
        uniform_int_distribution<int> dist(0, limit);

        switch(sort_ord){
            case 1:
                // dataSet = new int[limit];
                for(int i=0; i<limit; i++){
                    dataSet[i]=i;
                }
                break;
            case 2:
                // dataSet = new int[limit];
                for(int i=0; i<limit; i++){
                    dataSet[i]=dist(generator);
                    // cout<<dist(generator)<<" ";
                }
                break;
            case 3:
                // dataSet = new int[limit];
                for(int i=limit; i>0; i--){
                    dataSet[i]=i;
                }
                break;
            default:
                cout<<"\nError";
        }

        switch(sort_tech){
            case 1:
                bubble_sort();
                break;
            case 2:
                selection_sort();
                break;
            case 3:
                insertion_sort();
                break;
            case 4:
                merge_sort(dataSet, begin, limit-1);
                break;
            case 5:
                quick_sort(dataSet, begin, limit-1);
                break;
            default:
                cout<<"\nError";
        }
    }

    void bubble_sort(){
        cout<<endl;

        auto start = chrono::high_resolution_clock::now();
        int i,j,temp;

        for(i=0;i<limit-1;i++)				//First loop for passes
        {
            for(j=0;j<limit-i-1;j++)			//Second loop for comparision
            {
                if(dataSet[j]>dataSet[j+1])				//test need to compare
                {
                    temp=dataSet[j];
                    dataSet[j]=dataSet[j+1];
                    dataSet[j+1]=temp;
                }
            }
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);
        display(duration.count());
    }

    void selection_sort(){
        cout<<endl;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < limit - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < limit; ++j) {
                if (dataSet[j] < dataSet[min_index]) {
                    min_index = j;
                }
            }
            // Swap the minimum element with the first element of the unsorted part
            swap(dataSet[i], dataSet[min_index]);
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);

        display(duration.count());
    }

    void insertion_sort(){
        cout<<endl;
        auto start = chrono::high_resolution_clock::now();

        int i, j, temp;

        for(i=1;i<limit;i++)				//First loop for passes
        {
            temp = dataSet[i];

            for(j=i-1;j>=0 && dataSet[j]>temp;j--)			//Second loop for comparision
            {
                dataSet[j+1]=dataSet[j];
            }
            dataSet[j+1]=temp;
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);

        display(duration.count());
    }

    void merge(int array[], int left, int mid, int right){
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;
    
        auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];
    
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];
    
        auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;
    
        while ((indexOfSubArrayOne < subArrayOne) && (indexOfSubArrayTwo < subArrayTwo)) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
    
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        delete[] leftArray;
        delete[] rightArray;
    }

    void merge_sort(int arr[], int begin, int end){
        cout<<endl;
        auto start = chrono::high_resolution_clock::now();

        if (begin >= end){
            return;
        }
        int mid = begin + (end - begin) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);
        
        display(duration.count());
    }

    int partition(int arr[], int start, int end){  
        int index = 0, pivotElement = arr[end], pivotIndex;
        int* temp = new int[end - start + 1];
        for (int i = start; i <= end; i++){
            if(arr[i] < pivotElement){
                temp[index] = arr[i];
                index++;
            }
        }
    
        temp[index] = pivotElement;
        index++;
    
        for (int i = start; i < end; i++){
            if(arr[i] > pivotElement){
                temp[index] = arr[i];
                index++;
            }
        }

        index = 0;
        for (int i = start; i <= end; i++){  
            if(arr[i] == pivotElement){
                pivotIndex = i;
            }
            arr[i] = temp[index];
            index++;
        }
        return pivotIndex;
    }

    void quick_sort(int arr[], int begin, int end){
        cout<<endl;
        auto start = chrono::high_resolution_clock::now();

        if(begin < end){
            int partitionIndex = partition(arr, begin, end);
            quick_sort(arr, begin, partitionIndex - 1);
            quick_sort(arr, partitionIndex + 1, end);
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);

        display(duration.count());
    }

    void display(int time=0){
        // printf("\n Array Data: \n");
	    // for(int i=0; i<limit; i++)
        // cout<<"Data Set ["<<i<<"] = "<<dataSet[i]<<endl;

        cout << "\nTime taken by function: "<< time << " microseconds" << endl;
    }
};

int main(){

    analysis testCase1;

    return 0;
}