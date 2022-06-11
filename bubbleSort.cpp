#include<iostream>

using namespace std;

class demo{
	int *arr, n, temp;
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
				for(int j=0;j<n-i-1;j++){
					if(arr[j]>arr[j+1]){
						temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
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
