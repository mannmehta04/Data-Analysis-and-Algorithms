#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

class knapSackNode{
	public:
		int index;
		int weight,value;
		float vw;
	
		knapSackNode(int i,int w,int v){
			index=i; 
			weight = w;
			value = v;
			vw= (float)v/w;
		}
	
};

class knapScak{
	vector<knapSackNode> nodes;
	int totalWeight = 0;
	public:
		knapScak(int W){
			totalWeight = W;
		}
		void append(int w,int v){
			nodes.push_back(knapSackNode(nodes.size()+1,w,v));
		}
		
		void display(){
			cout<<setw(6)<<"W : "<<totalWeight<<endl;
			cout<<setw(7)<<"Index"<<setw(7)<<"Value"<<setw(7)<<"Weight"<<setw(7)<<"v/w"<<endl;
			for(int i=0;i<nodes.size();i++){
				cout<<setw(7)<<nodes[i].index<<setw(7)<<nodes[i].value<<setw(7)<<nodes[i].weight<<setw(7)<<setprecision(2)<<nodes[i].vw<<endl;
			}
		}
		
	
	
		void knapScakFra(int option,bool isFra){
			sort(nodes.begin(),nodes.end(),[&option](knapSackNode &a,knapSackNode &b){
			if(option == 1)
				return a.value>b.value;
			else if(option == 2)
				return a.weight<b.weight;	
			else 
				return a.vw>b.vw;
			});
			
			int temp = 0,tempW = totalWeight;
			cout<<setw(7)<<"Index"<<setw(7)<<"Value"<<setw(7)<<"Weight"<<setw(10)<<"R Weight"<<endl;
		    cout<<setw(7)<<"-"<<setw(7)<<"-"<<setw(7)<<"-"<<setw(10)<<totalWeight<<endl;
			for(int i=0;i<nodes.size();i++){
				if(tempW >= nodes[i].weight){
					tempW -= nodes[i].weight;
				    cout<<setw(7)<<nodes[i].index<<setw(7)<<nodes[i].value<<setw(7)<<nodes[i].weight<<setw(10)<<tempW<<endl;
					temp += nodes[i].value;
				}else{
					if(isFra == true){
						int f = ((float)tempW/nodes[i].weight)*nodes[i].value;
						temp += f;
						cout<<setw(7)<<nodes[i].index<<setw(7)<<f<<setw(7)<<tempW<<setw(10)<<0<<endl;
						tempW -= nodes[i].weight;
					}
					break;
				}
			}
			cout<<setw(14)<<"----"<<endl;
			cout<<setw(14)<<temp<<endl;
		}
};
int main(){
	system("color F0");

	knapScak ks(60);
	ks.append(5,30);
	ks.append(10,40);
	ks.append(15,45);
	ks.append(22,77);
	ks.append(25,90);
	
	ks.display();
	
	cout<<endl<<" 0/1 Knapsack"<<endl;
	cout<<"\n Maximum by value"<<endl;
	ks.knapScakFra(1,false);
	cout<<"\n Minimum by weight"<<endl;
	ks.knapScakFra(2,false);
	cout<<"\n Maximum by v/w"<<endl;
	ks.knapScakFra(3,false);
	
	cout<<endl<<" Fractional Knapsack"<<endl;
	cout<<"\n Maximum by value"<<endl;
	ks.knapScakFra(1,true);
	cout<<"\n Minimum by weight"<<endl;
	ks.knapScakFra(2,true);
	cout<<"\n Maximum by v/w"<<endl;
	ks.knapScakFra(3,true);


}
