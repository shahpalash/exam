#include<thread>
#include<iostream>
using namespace std;
int a[5][5],g1[5],g2[5][5],g3[5][5][5],j1[5][5][5],g4[5][5][5][5],j2[5][5][5][5];
void TSP(int s)
{
        int min1=0,min=0;
	for(int i=2;i<=4;i++)
	{
		switch(s)
		{
			case 0:
			g1[i]=a[i][1];
			break;
			case 1: int v1,v2;
				if(i==2)
        			{
				 v1=3;
				 v2=4;
				}
				if(i==3)
        			{
				 v1=2;
				 v2=4;
				}
				if(i==4)
        			{
				 v1=2;
				 v2=3;
				}
				g2[i][v1]=a[i][v1]+g1[v1];
				g2[i][v2]=a[i][v2]+g1[v2];
				break;
			case 2:
				if(i==2)
        			{
				 v1=3;
				 v2=4;
				}
				if(i==3)
        			{
				 v1=2;
				 v2=4;
				}
				if(i==4)
        			{
				 v1=2;
				 v2=3;
				}


				g3[i][v1][v2]=a[i][v1]+g2[v1][v2];
                                min=g3[i][v1][v2];
                                j1[i][v1][v2]=v1;
				g3[i][v1][v2]=a[i][v2]+g2[v2][v1];
                                if(min>g3[i][v1][v2])
				{
					 j1[i][v1][v2]=v2;
				}
				else
				{
					g3[i][v1][v2]=min;
				}
				break;
			case 3:

				if(i==2)
        			{
				 v1=3;
				 v2=4;
				}
				if(i==3)
        			{
				 v1=2;
				 v2=4;
				}
				if(i==4)
        			{
				 v1=2;
				 v2=3;
				}

				g4[1][2][3][4]=a[1][i]+g3[i][v1][v2];
                                 if(i==2)
					{
						min1=g4[1][2][3][4];
						j2[1][2][3][4]=i;
						g4[1][2][3][4]=a[1][3]+g3[3][2][4];
					}
				else
				{
					if(min1>g4[1][2][3][4])

					{
						j2[1][2][3][4]=i;
						min1=g4[1][2][3][4];
					}
                                      else
					{
						g4[1][2][3][4]=min1;
					}

				}
			break;

		}
	}
}

int main()
{
int min=0,v1,v2,v3,v4;
cout<<"Enter 4 * 4 matrix elements";
for(int i=1;i<=4;i++)
{
for(int j=1;j<=4;j++)
{
cin>>a[i][j];
}
}
cout<<"\nEntered 4 * 4 matrix elements are ";
for(int i=1;i<=4;i++)
{cout<<"\n";
for(int j=1;j<=4;j++)
{
cout<<a[i][j]<<" ";
}
}
for(int S=0;S<4;S++)
{
thread t(TSP,S);
t.join();
}
cout<<"\n optimal tour has a cost :"<<g4[1][2][3][4];
				if(j2[1][2][3][4]==2)
        			{
				 v1=2;
				 v2=3;
				 v3=4;
				}
				if(j2[1][2][3][4]==3)
        			{
				 v1=3;
				 v2=2;
				 v3=4;
				}
				if(j2[1][2][3][4]==4)
        			{
				 v1=4;
				 v2=2;
				 v3=3;
				}

cout<<"\n optimal tour is: 1-"<<j2[1][2][3][4]<<"-"<<j1[v1][v2][v3]<<"-";
int k=j1[v1][v2][v3];
if(k==v2)
cout<<v3<<"-1";
else
cout<<v2<<"-1";

return 0;

}
