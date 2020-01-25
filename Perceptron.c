#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void erase(int* array, int index)
{
	int x = index;
	for (x; x<4; x++)
		*(array+x) = *(array+x+1);
}

int equal(int* array, int* other)
{
	int id = 0;
	for(id; id<4; id++)
	{
		printf("arr[1]'s %d,   arr[2]'s %d\n",*(array + id),*(other + id));
		if (*(array + id) != *(other + id))
			return 0;
	}
	return 1;
}
int main()
{
	float n= 0.1, w0=0.0, w1=0.0, ans=0, e = 0.0, b = -0.2;
	int xin[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } };
	int xans[4]={0,0,0,1}, anslst[4];
	int count = 0;

	int u=0;
	for(u; u<4; u++)
		scanf("%d%d", &xin[u][0], &xin[u][1]);

	while (1)
	{
		int i = 0;
		for (i; i < 4; i++)
		{
			ans = w0*xin[i][0] + w1*xin[i][1] + b;
			if (ans < 0)
				ans = 0;
			anslst[count] = ans;
			count++;
			int x = 0;
			for (x; x < count; x++)
			{
				printf("id= %d, x= %d, y= %d\n", x, xans[x], anslst[x]);
				if (anslst[x] != xans[x])
				{
					int y = anslst[x];
					erase(anslst, x);
					count--;
					e = abs(y - xans[x]);
					w0 = n * e * xin[i][0];
					w1 = n * e * xin[i][1];
					ans = w0*xin[i][0] + w1*xin[i][1] + b;
					if (ans >= 0)
						ans = 1;
					anslst[count] = ans;
					count++;
				}
			}
		}
		if (equal(anslst, xans))
			break;
	}
	int z = 0;
	for (z; z<4; z++)
	{
		printf("%d ",anslst[z]);
	}
	getch();
}
