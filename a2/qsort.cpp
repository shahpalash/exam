#include <iostream>
#include <pthread.h>
#define max 20
using namespace std;

int t;

class quick
{
	int* arr;
	int n;
	public:
	int high;
	int low;
	quick(int n1)
	{
	  n=n1;
	}
	quick(quick *obj)
	{

		this->n=obj->n;
		this->arr=obj->getArr();
	}
	int* getArr()
	{
		return arr;
	}
	void accept();
	void display(int, int);
	void quicksort(int,int);
	int partition(int,int);
	static void* thread_function(void *ptr)
	{
		quick* q= static_cast<quick *>(ptr);
		q->quicksort(q->low,q->high);
	}
};

void quick :: accept()
{
	int i;
	arr = new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter data: "<<endl;
		cin>>arr[i];
	}
}

void quick :: display(int l, int h)
{
	int i;
	cout<<"The array is: "<< endl;
	for(i=l;i<h;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout << endl;
	cout<<endl;
}

void quick :: quicksort(int low,int high)
{
	int piv_index;
	pthread_t th1,th2;
	quick *q1,*q2;
	t++;
	cout << "ID: " << t << ": \n";
	display(low, high);
	if(low<high)
	{
		piv_index=partition(low,high);

		q1= new quick(this);
		q2= new quick(this);

		q1->low=low;
		q1->high=piv_index-1;
		q2->low=piv_index+1;
		q2->high=high;

		pthread_create(&th1,NULL,quick :: thread_function,(void *) q1);
		pthread_create(&th2,NULL,quick :: thread_function,(void *) q2);

		pthread_join(th1,NULL);
		pthread_join(th2,NULL);
	}

}

int quick :: partition(int low,int high)
{
	int i,j,pivot,temp;
	t=0;
	pivot=arr[low];
	i=low+1;
	j=high;

	while(i<=j)
	{
		while(arr[i]<=pivot)
			i++;

		while(arr[j]>pivot)
			j--;

		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	arr[low]=arr[j];
	arr[j]=pivot;

	return j;
}

int main()
{
	int no;
	cout<<"Enter the size of array: "<<endl;
	cin>>no;
	quick *q;
	q= new quick(no);
	q->accept();
	cout<<"Before Sorting: "<<endl;
	q->display(0, no);
	q->low=0;
	q->high=no-1;
	void *ptr=reinterpret_cast<void *>(q);
	quick::thread_function(ptr);
	cout<<"After Sorting: "<<endl;
	q->display(0, no);
	return 0;
}
