#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class knapSackEle{
	public:
		int index;
		int weight,value;
		float ratio;

		knapSackEle(){
			index = weight = value = ratio = 0;
		}
	
		knapSackEle(int index,int weight,int value){
			this->index = index;
			this->weight = weight;
			this->value = value;
			this->ratio = (float)value/weight;
		}
};

class knapSack{

	vector<knapSackEle> Element;
	int totalWeight;

	public:

        knapSack(){
            totalWeight = 0;
        }

		knapSack(int totalWeight){
			this->totalWeight = totalWeight;
		}

		void addData(int w,int v){
			Element.push_back(knapSackEle(Element.size()+1,w,v));
		}
		
		void display(){
			cout<<"Total Weight : "<<totalWeight<<endl;
			cout<<"\tIndex\t"<<"Value\t"<<"Weight\t"<<"Ratio"<<endl;
			for(int i=0;i<Element.size();i++){
				cout<<"\t"<<Element[i].index<<"\t"<<Element[i].value<<"\t"<<Element[i].weight<<"\t"<<Element[i].ratio<<endl;
			}
		}

		void knapSackFraction(int option,bool isFra){
            
			sort(Element.begin(),Element.end(),[&option](knapSackEle &a,knapSackEle &b){
			if(option == 1)
				return a.value > b.value;
			else if(option == 2)
				return a.weight < b.weight;	
			else 
				return a.ratio > b.ratio;
			});
			
			int finalValue = 0,tempWeight = totalWeight;
			cout<<"\n\t"<<"Total Weight:"<<"\t"<<totalWeight<<endl;
			cout<<"\t"<<"Index"<<"\t"<<"Value"<<"\t"<<"Weight"<<"\t"<<"Remaining Weight"<<endl;

			for(int i=0;i<Element.size();i++){
				if(tempWeight >= Element[i].weight){
					tempWeight -= Element[i].weight;
				    cout<<"\t"<<Element[i].index<<"\t"<<Element[i].value<<"\t"<<Element[i].weight<<"\t"<<tempWeight<<endl;
					finalValue += Element[i].value;
				}
                else{
					if(isFra == true){
						int f = ((float)tempWeight/Element[i].weight)*Element[i].value;
						finalValue += f;
						cout<<"\t"<<Element[i].index<<"\t"<<f<<"\t"<<tempWeight<<"\t"<<0<<endl;
						tempWeight -= Element[i].weight;
					}
					break;
				}
			}
			cout<<"\t\t"<<"----"<<endl;
			cout<<"\t\t"<<finalValue<<endl;
		}
};

int main(){

    int method, order;

	// Total Weight
	knapSack k1(60);

    // Weight and Value
	k1.addData(12,4);
	k1.addData(2,2);
	k1.addData(4,10);
	k1.addData(1,2);
	k1.addData(1,1);
	
	k1.display();

    cout<<"\nSelect Knapsack Method:";
    cout<<"\n1. 0/1 Knapsack\n";
    cout<<"2. Fractional Knapsack\n";
    cin>>method;

    cout<<"\nSelect Knapsack Order:";
    cout<<"\n1. Highest Value\n";
    cout<<"2. Lowest Weight\n";
    cout<<"3. Highest Ratio\n";
    cin>>order;

    switch(method){

        case 1:
            cout<<endl<<" 0/1 Knapsack"<<endl;
            switch (order){
            case 1:
                cout<<"\n Highest value"<<endl;
	            k1.knapSackFraction(order,false);
                break;
            case 2:
                cout<<"\n Lowest weight"<<endl;
	            k1.knapSackFraction(order,false);
                break;
            case 3:
                cout<<"\n Highest ratio"<<endl;
	            k1.knapSackFraction(order,false);
            default:
                break;
            }
            break;

        case 2:
            cout<<endl<<" Fractional Knapsack"<<endl;
            switch (order){
            case 1:
                cout<<"\n Highest value"<<endl;
	            k1.knapSackFraction(order,true);
                break;
            case 2:
                cout<<"\n Lowest weight"<<endl;
                k1.knapSackFraction(order,true);
                break;
            case 3:
                cout<<"\n Highest ratio"<<endl;
	            k1.knapSackFraction(order,true);
                break;
            default:
                break;
            }
            break;
        
        default:
            cout<<"Error";
    }
}