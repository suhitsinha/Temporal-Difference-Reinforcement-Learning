#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>


int main(int argc, char **argv)
{
	int i, j = 0;
	int LineCnt = atoi(argv[2]) - 3;

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("File not exists\n");
		exit(0);
	}

	//Read the number of states from the file
	int stateNum ;
	fscanf(fp,"%d",&stateNum);

	//Read number of actions from the file
	int actionNum;
	fscanf(fp,"%d",&actionNum);

	//Read the discount factor from file
	double disFactor, alpha = 0.000001;
	fscanf(fp,"%lf",&disFactor);

	double **simulation = (double **)malloc( LineCnt * sizeof(double *));

	for (i=0; i< LineCnt; i++)
		simulation[i] = (double *)malloc(3 * sizeof(double));

	//Read the values from the file
	for(i=0; i< LineCnt-1; i++)
	{
		for (j=0; j< 3; j++)
		{
			fscanf(fp,"%lf",&simulation[i][j]);
		}
	}
	
	fscanf(fp,"%lf",&simulation[LineCnt-1][0]);

	simulation[LineCnt - 1][1] = -9999;
	simulation[LineCnt - 1][2] = -9999;

	double *StateValue = (double *)malloc( stateNum * sizeof(double));
	
	//Initialize all the state values to zero	
	for (i = 0; i <stateNum; i++ )
		StateValue[i] = 0;

	//Iterate the loop to converge the state values
	while (j < 20000)
	{
		for (i=0; i< LineCnt-1; i++)
		{	
			//Calculate the value using temporal difference
			StateValue[(int)simulation[i][0]] = StateValue[(int)simulation[i][0]] + alpha * (simulation[i][2] + (disFactor * 				StateValue[(int)simulation[i + 1][0]]) - StateValue[(int)simulation[i][0]]);
		}
			j++;
	}
	
	//Print the state values	
	for (i=0; i < stateNum; i++)
		printf("%.8f\n", StateValue[i]);

	fclose(fp);

	return 0;
}
