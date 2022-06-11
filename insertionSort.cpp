#include<iostream>

using namespace std;

//insertion Sort 21CP314-Vivek

class demo{
	int *arr, n, key, i, j;
	public:
		demo(){
			cout<<"How many element you want::";
			cin>>n;
			arr = new int[n];
			cout<<"Enter "<<n<<" Elements::\n";
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
		}
		void sort(){
			for(i=1;i<n;i++){
				key = arr[i];
				j = i-1;
				while(j >= 0 && arr[j] > key){
					arr[j+1] = arr[j];
					j--;
				}
				arr[j+1] = key;
			}
		}
		void display(){
			cout<<"\nArray elements are::";
			for(int i=0;i<n;i++){
				cout<<endl<<arr[i];
			}
		}
};

int main(){
	demo ob1;
	ob1.sort();
	ob1.display();
}
