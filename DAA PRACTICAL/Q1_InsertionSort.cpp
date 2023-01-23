#include<iostream>
#include<fstream>
using namespace std;

const int arrSize=500;

template<class t>
class insertionSort{
	t arr[arrSize];
	
	public:
	
	
	void getData(int n){
		for (int i=0; i<n; i++){
		int r=rand()%100;
		arr[i]=r;
	}
	}//input random values
	
	void displayData(int n){
		for (int i=0; i<n; i++){
			cout<<"\t"<<arr[i];	   
		}
	}//output the array
	
	int iSort(int n){
		
		int count=0;
		for (int i=0; i<n; i++){
			t key=arr[i];
			int j=i-1;
			while(j>=0 && arr[j]>key){
				arr[j + 1] = arr[j];
				count++;
				j=j-1;
			}
	        arr[j + 1] = key;
			count++;
		}
		cout<<endl<<"-> Number of comparisions : "<<count<<endl;
		return count;
	}

};

int main(){
	insertionSort<int> obj;
	int size=30;
	int i=0;
	int count=0;
	int iter=20;
	
	ofstream excelFile;
	excelFile.open("Q1_excel.csv");
	excelFile<<"SIZE(n)"<<","<<" COMPARISIONS"<<","<<"Log (n)"<<","<< "n Log (n)"<<endl;
	while (i<iter && size<=arrSize){
		cout<<endl<<endl<<"================================"<<endl;
		cout<<endl<<"-> Size of the array - "<<size<<endl;
		obj.getData(size);
		
		cout<<endl<<"-> Array before sorting - " ;
		obj.displayData(size);
		
		count=obj.iSort(size);
		excelFile<<size<<","<<count<<endl;
		
		cout<<endl<<"-> Array after sorting - ";
		obj.displayData(size);
		size=size+20;
		i++;
	}
	excelFile.close();
}

