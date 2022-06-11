#include<iostream>

using namespace std;

//quick Sort Vivek-21CP314;

class demo{
	public:
		int *a, n;
		demo(){
			cout<<"How many element you want::";
			cin>>n;
			a = new int[n];
			cout<<"Enter "<<n<<" Elements::\n";
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
		}
		void swapEle(int i, int j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		int partition(int l, int h){
			int key = a[l];
			int i = l;
			int j = h;
			while(i<j){
				while(a[i] <= key) i++;
				while(a[j] > key) j--;
				if(i<j){
					swapEle(i, j);
				}
			}
			swapEle(j,l);
			return j;
		}
		void sort(int l, int h){
			if(l<h){
				int k = partition(l, h);
				sort(l, k-1);
				sort(k+1, h);
			}
		}
		void display(){
			cout<<"\nArray elements are::";
			for(int i=0;i<n;i++){
				cout<<endl<<a[i];
			}
		}
};

int main(){
	demo ob1;
	ob1.sort(0, ob1.n-1);
	ob1.display();
}
