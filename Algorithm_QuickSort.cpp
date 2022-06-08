#include <iostream>
using namespace std;
const int MAX=100;

enterArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Value of array "<<i;
		cout<<" is ";
		cin>>arr[i];
	}
}
printArray(int arr[], int n)
{
	 for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
        cout << "\n"; 
}

void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}

int partition(int arr[], int low,int high)
{
	int pivot=arr[high];
	int left=low;
	int right=high-1;
	while(true)
	{
		while(left<=right && arr[left]<pivot) left++;
		while(left<=right && arr[right]>pivot) right--;
		if(left>=right) break;
		swap(arr[left],arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[],int low,int high)
{
   if(low<high)
   {
   	 int pi=partition( arr, low, high);
   	 quickSort(arr,low,pi-1);
   	 quickSort(arr,pi+1,high);
   }	
}

int main()
{
	int n;
	int arr[MAX];
	cout<<"Nhap n: ";
	cin>>n;
	enterArray(arr,n);
	quickSort(arr,0,n-1);
	cout<<"\nSorted array: ";
	printArray(arr,n);
	return 0;
}
