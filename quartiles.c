#include <stdio.h>
#include <conio.h>

int i, j, ll, up, cl, nc, l[100], u[100], f[100], sf, am, cf[100], temp, indext[3], x[100];

int continuous()
{
	printf("Enter the lower limit");
	scanf("%d", &ll);
	
	printf("Enter the class length");
	scanf("%d", &cl);
	
	printf("Enter the total number of classes");
	scanf("%d", &nc);
	
	printf("\n");
	
	// limit calculations
	
	for(i=0; i<nc; i++)
	{
		up = ll + cl;
		l[i] = ll;
		u[i] = up;
		ll = up;
		x[i] = ((float)l[i] + (float)u[i])/2;
	}
	
	for(i=0; i<nc; i++)
	{
		printf("Enter frequency for class %d-%d : ", l[i], u[i]);
		scanf("%d", &f[i]);
	}
	printf("\n");
	cf[0] = f[0];
	
	for(i=0; i<nc; i++)
	{
		cf[i+1] = cf[i] + f[i+1];
	}
	for(i=0; i<nc; i++)
	{
		sf +=f[i];
	}
	for(i=0; i<nc; i++)
	{
		for(j=0; j<3; j++)
		{
			if(((sf*(j+1)/4)>=cf[i]))
			{
				indext[j] = i+1;
			}
		}
	}
	printf("Class \t\t FREQ \t\t C.F. \n");
	for(i=0; i<35; i++)
	{
		printf("-");
	}
	for(i=0; i<nc; i++)
	{
		printf("\n %d - %d\t %d\t %d\n", l[i], u[i], f[i], cf[i]);
	}
	printf("Total %d\n", sf);
	printf("\n\n");
	
	for(i=0; i<3; i++)
	{
		printf("The Q %d is: %.2f\n", i+1, l[indext[i]]+(((((float)sf*(i+1)/(float)4) - cf[indext[i] - 1]) / f[indext[i]])*cl));
	}
	
}

int main()
{
	continuous();
	return(0);
}
