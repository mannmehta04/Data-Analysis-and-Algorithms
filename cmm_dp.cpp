#include<iostream>
using namespace std;

class chainmatrix{
    int no=INT_MAX;
    int d[6]={13,5,89,3,34};
	
	public:
    
    int calculate(int i,int j){

        if(i==j)	return 0;
        
        int min1 = INT_MAX;
        for(int k=i;k<j;k++){
            no = calculate(i,k)+calculate(k+1,j)+(d[i-1]*d[k]*d[j]);
            if(no<min1)
				min1 = no;
        }
        return min1;
    }
};
int main(){
    chainmatrix c1;
    cout<<"Minimum / Optimum numberr of solutions: "<<c1.calculate(1,4)<<endl;
    return 0;
}
