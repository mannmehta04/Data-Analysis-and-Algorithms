#include <iostream>
#include <vector>
using namespace std;

class countingSort {
    vector<int> v1;
    vector<int> counterArr;
    vector<int> sortedArr;

public:
    countingSort() {}

    countingSort(vector<int>& v1) {
        this->v1 = v1;
    }

    int findArrSize(vector<int>& v1) {
        int max = 0;
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] > max)
                max = v1[i];

        return max;
    }

    void findOccurrence() {
        int maxSize = findArrSize(v1) + 1;
        counterArr.resize(maxSize);

        for (int i = 0; i < v1.size(); i++)
            counterArr[v1[i]]++;
    }

    void sort() {
        findOccurrence();
        sortedArr.resize(v1.size());

        int index = 0;
        for (int i = 0; i < counterArr.size(); i++)
            while (counterArr[i] > 0) {
                sortedArr[index] = i;
                index++;
                counterArr[i]--;
            }
    }

    void display() {
        for (int i = 0; i < sortedArr.size(); i++)
            cout << sortedArr[i] << " ";
        cout << endl;
    }
};

int main() {
    vector<int> v1 {2, 4, 5, 3, 1};

    countingSort c1(v1);
    c1.sort();
    c1.display();

    return 0;
}
