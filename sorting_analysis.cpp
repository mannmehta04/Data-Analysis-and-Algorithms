#include<random>
#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

class analysis{

    bool ascend=false;
    bool desend=false;
    int *dataSet;
    int limit, sort_tech, sort_ord;

    public:

    analysis(){
        cout<<"Enter limit of numbers: ";
        cin>>limit;
        dataSet = new int[limit];

        cout<<"\nSelect Sorting Order:\n";
        cout<<"1. Ascending\n";
        cout<<"2. Desending\n\n";
        cin>>sort_ord;

        cout<<"\nSelect Sorting Technique:\n";
        cout<<"1. Bubble\n";
        cout<<"2. Selection\n";
        cout<<"3. Insertion\n\n";
        cin>>sort_tech;
        
        assaign_data();
    }

    void assaign_data(){
        random_device seed;
        mt19937 generator(seed());
        uniform_int_distribution<int> dist(0, limit);

        for(int i=0; i<limit; i++){
            dataSet[i]=dist(generator);
            // cout<<dist(generator)<<" ";
        }

        switch(sort_ord){
            case 1:
                ascend = true;
                desend = false;
                break;
            case 2:
                ascend = false;
                desend = true;
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
            default:
                cout<<"\nError";
        }
    }

    void bubble_sort(){
        cout<<endl;

        if(ascend){
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
        else if(desend){
            auto start = chrono::high_resolution_clock::now();
            int i,j,temp;

            for(i=0;i<limit-1;i++)				//First loop for passes
            {
                for(j=0;j<limit-i-1;j++)			//Second loop for comparision
                {
                    if(dataSet[j]<dataSet[j+1])				//test need to compare
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
    }

    void selection_sort(){
        cout<<endl;

        if(ascend){
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
        else if(desend){
            auto start = chrono::high_resolution_clock::now();

            int i,j,temp;
            
            for (int i = 0; i < limit - 1; ++i) {
                int min_index = i;
                for (int j = i + 1; j < limit; ++j) {
                    if (dataSet[j] > dataSet[min_index]) {
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
    }

    void insertion_sort(){
        cout<<endl;
        if(ascend){
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

        else if(desend){
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
    }

    void display(int time){
        printf("\n Array Data: \n");
	    for(int i=0; i<limit; i++)
        cout<<"Data Set ["<<i+1<<"] = "<<dataSet[i]<<endl;

        cout << "\nTime taken by function: "<< time << " microseconds" << endl;
    }
};

int main(){

    analysis testCase1;

    return 0;
}