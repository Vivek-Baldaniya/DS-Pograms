#include <iostream>  
  
using namespace std;  
  
//21CP314-Vivek

int getMax(int a[], int n) 
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(int a[], int n)  
{  
  int max = getMax(a, n); 
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  
void printArr(int a[], int n)  
{  
  for (int i = 0; i < n; ++i)  
    cout<<a[i]<<" ";  
}  
int main()  
{ 
  int n;
  int *a;  
  cout<<"Enter the Element:"<<endl;
  cin>>n;
  a=new int[n];
  cout<<"Enter Element:"<<endl;
  for(int i=0;i<n;i++)
  {
  	cin>>a[i];
  }
  bucket(a, n);  
  cout<<"\nSorted array elements are - \n";  
  printArr(a, n);  
}