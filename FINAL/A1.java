class BinarySearch
{
	static java.util.Scanner sc=new java.util.Scanner(System.in);
	static int binarysearch(int[] arr,int element)
	{
		int low,high,mid,tmp;
		low=0;
		high=arr.length-1;
		mid=((high+low)/2);
		while(low<=high)
		{
			//System.out.println("Mid :"+mid+" "+arr[mid]+"high/low "+high+"/"+low);
			mid=(high+low)/2;
			tmp=arr[mid];
			if(tmp==element)
				return mid;
			else if(tmp<element)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		return -1;
	}
	public static void main(String args[])
	{
		System.out.println("Enter number of elements in array :");
		int n=sc.nextInt();
		int[] arr=new int[n];
		System.out.println("Enter the elements ");
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		java.util.Arrays.sort(arr);
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+" ");
		}
		System.out.println("Enter element to be searched :");
		System.out.println(binarysearch(arr,sc.nextInt()));
		
		
	}
}
