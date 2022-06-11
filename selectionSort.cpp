#include<iostream>

using namespace std;

class demo{
	int *arr, n, temp, min;
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
		// Vivek-21CP314
		void sort(){
			for(int i=0;i<n;i++){
				min = i;
				for(int j=i+1;j<n;j++){
					if(arr[i] > arr[j]){
						min = j;
					}
				}
				temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
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
