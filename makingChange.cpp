#include<iostream>
#include<map>
#include<chrono>
using namespace std;
using namespace std::chrono;

class change{

    //static set of bank notes
    int notes[10] { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

    //money is user input to get change
    //debit is used to check deducting money after each note ~~optional~~
    //totalNotes shows total number of notes of all amounts
    //transactTime shows transaction time
    //lastBigNote shows last biggest note
    int money, totalNotes=0, transactTime=0, lastBigNote=9;

    //dataMap variables
    int freq, note;
    map<int,int> dataMap;

    public:
    change(){
        money = 0;
        debit = 0;
    }

    change(int money){
        this->money = money;
    }

    void getChange(){
        auto start = chrono::high_resolution_clock::now();

        int firstNoteSet;
        for(int i=lastBigNote; i>=0; i--){
            if(money>=notes[i]){
                firstNoteSet=money/notes[i];
                lastBigNote=i;
                money -= (notes[i]*firstNoteSet);
                dataMap[notes[i]]=firstNoteSet;
                totalNotes++;
            }
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);
        transactTime = duration.count();
    }

/*
Below code uses iterative method; not optimal solution, kept for future reference

    void getChange(){
        auto start = chrono::high_resolution_clock::now();
        for(int i=lastBigNote; i>=0; i--){
            if(money>=notes[i]){
                // found smaller matching note
                // cout<<notes[i];
                
                //store retrived note amount
                debit += notes[i];

                //reduce amount from requested amount
                money -= notes[i];
                // cout<<money<<endl;

                //change the last biggest note to the note you took last time
                lastBigNote=i;

                //increment number of taken note
                totalNotes++;

                //store data in map
                dataMap[notes[i]]++;

                //iterative call
                getChange();
                break;
            }
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<microseconds>(stop - start);
        transactTime = duration.count();
        // cout<<"debit col:"<<debit<<endl;
        // cout<<"remaing mon:"<<money<<endl<<endl;
    }
*/

    void display(){
        cout<<"\n\t Total Notes fetched: \t"<<totalNotes<<"\n\n";
        map<int, int>::iterator it;
        cout<<"\t Notes \t\t Number of Notes"<<endl;
        for(it=dataMap.begin();it!=dataMap.end();it++){
            cout<<"\t "<<it-> first<<" \t\t "<<it->second<<endl;
        }
        cout<<"\n\t Transaction time: \t"<<transactTime<<" microseconds\n\n";
    }
};

int main(){

    // change c1(450);
    change c1(127150);
    c1.getChange();
    c1.display();

    return 0;
}