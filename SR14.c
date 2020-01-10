//��������������� ������ 13. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>
#include <math.h>
#include <time.h>

int filling(int low, int up, int qty, int *array); //��������� �������
int output(int qty, int *array);
int null(int qty,int *array);
int maximum(int qty, int *array, int *max);
int savetofile(int qty, int *array);
int readfromfile(int *qty, int *array);
int checkn(int qty, int nmax, int *n);
int replace(int n,int *array);
int checkposnum(int qty, int *pos, int *num);
int arrayinsert(int low, int up,int pos, int num, int *qty, int *array);
int arraycutoff(int pos, int num, int *qty, int *array);
int checksize(int *arraysize);
int sort(int qel, int *qas, int *qco, int *array);
int sort1(int qel, int *qas, int *qco, int *array);
int sortn(int qel, int *qas, int *qco, int *array);
int QuickSort(int first, int last, int *array);
int swap(int *x, int *y);

int main(void)//������� �������
{
	int *array, arraysize,n,nmax,position,number,low,up,asgn=0,cmpr=0,asgn1=0,cmpr1=0,asgnn=0,cmprn=0;//����������� ����������
	double etime,etime1,etimen;
	time_t start,finish;
	printf("Enter quantity of elements in array: ");//���� ���������� ��������� � �������
	scanf("%d", &arraysize);
	checksize(&arraysize);
	array = malloc((arraysize+1)*sizeof(int));//�������� �������
	printf("Enter limits: ");//���� ��������
	scanf("%d %d", &low,&up);
	if (low>up)
	{
		up=low-up;
		low=low-up;
		up=low+up;
	}
	filling(low,up,arraysize,array);//��������� �������
	savetofile(arraysize,array);//���������� ������� � ����
	readfromfile(&arraysize,array);//���������� ������� �� �����
	printf("Array\n",asgn);
	//output(arraysize,array);//����� �������
	readfromfile(&arraysize,array);//���������� ������� �� �����
	start=clock();
	//sort(arraysize, &asgn, &cmpr,array);//���������� �������
	QuickSort(1,arraysize,array);
	finish=clock();
	etime=(finish-start)/CLOCKS_PER_SEC;
	printf("Standart sorting\n",asgn);
	//output(arraysize,array);//����� �������
	printf("Quantity of assignments: %d\n",asgn);
	printf("Quantity of comparisons: %d\n\n",cmpr);
	readfromfile(&arraysize,array);//���������� ������� �� �����
	start=clock();
	sort1(arraysize, &asgn1, &cmpr1,array);//���������� �������
	finish=clock();
	etime1=(finish-start)/CLOCKS_PER_SEC;
	printf("Improved sort\n",asgn);
   //	output(arraysize,array);//����� �������
	printf("Quantity of assignments: %d\n",asgn1);
	printf("Quantity of comparisons: %d\n\n",cmpr1);
	readfromfile(&arraysize,array);//���������� ������� �� �����
	start=clock();
	sortn(arraysize, &asgnn, &cmprn,array);//���������� �������
	finish=clock();
	etimen=(finish-start)/CLOCKS_PER_SEC;
	printf("Improved+\n",asgn);
	//output(arraysize,array);//����� �������
	printf("Quantity of assignments: %d\n",asgnn);
	printf("Quantity of comparisons: %d\n\n",cmprn);
	printf("Method       |  Standart  |  Improved  |  Improved+ |\n");
	printf("Assignments  | %10d | %10d | %10d |\n",asgn,asgn1,asgnn);
	printf("Comparisons  | %10d | %10d | %10d |\n",cmpr,cmpr1,cmprn);
	printf("Elapsed time | %10.3lf | %10.3lf | %10.3lf |\n",etime,etime1,etimen);
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}

int filling(int low, int up, int qty, int *array)//���������� �������
{
	int i;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qty ; i++)//���������� �������
	{
		array[i]=low+(up-low)*rand()/RAND_MAX;
	}
}

int output(int qty, int *array)//����� �������
{
	int i,j,cycles;//����������� ����������
	if (qty>0)
	{
		printf("|   Element   |");
	}
	else
	{
		printf("Array has no elements\n");
	}
	for (i = 1; i <=qty; i++) //���� �� ���� ���������
	{
		printf(" %10d |",i);//����� ������ �������� � �������
		if ((i%5==0)&&(i!=qty)) //����������� ����� ������
		{
			printf("|    Value    |");
			for (j=4; j >=0; j--)//����� ��������
			{
				printf(" %10d |",(array[i-j]));
			}
			printf("|   Element   |");
		}
		else //��� ���������� �������� � �������
		{
			if (i==qty)
			{
				if (i%5!=0)
				{
					printf("\n");
				}
				printf("|    Value    |");//����� ��������
				if (i%5==0)
					cycles=5;
				else
					cycles=(i%5);
				for (j=(cycles-1); j >=0; j--)
				{
					printf(" %10d |",array[i-j]);
				}
				printf("\n\n"); //�������� ������ ������ ����� ������
			}
		}
	}
}

int null(int qty, int *array)//��������� �������
{
	int i;//����������� ����������
	for (i = 1; i <=qty; i++)//���������� ������� ������
	{
		array[i-1]=0;
	}
}

int maximum(int qty, int *array, int *max)//����� ������������� ��������
{
	int i;//����������� ����������
	*max=-array[i];//������������� ������������� �������� ������ �� ���������
	for (i = 1; i <=qty; i++)//������ �� ���� ���������
	{
		if (max>array[i-1])//�������� ������ ������������� ��������
		{
			*max=array[i-1];//������� ������ ������������� ��������
		}
	}
	printf("Maximum: %d |\n",*max);//����� ������������� ��������
}

int savetofile(int qty, int *array)//���������� ������� � ����
{
	FILE *filepointer;//����������� ����������
	int i;
	filepointer = fopen("SR12", "w");//�������� �����
	if (filepointer==NULL)//�� ������� �������
	{
		//��������� �� ������
		exit(1);//�����
	}
	else//������� �������
	{
		for (i = 1; i <= qty; i++)//������ � ����
		{
			fprintf(filepointer, "%d ",array[i]);
		}
		fclose(filepointer);//�������� �����
	}
}

int readfromfile(int *qty, int *array)
{
	FILE *filepointer;//����������� ����������
	int i=1;
	*qty=0;//����� ���������� ��������� � �������
	filepointer = fopen("SR12", "r");//�������� �����
	if (filepointer==NULL)//�� ������� �������
	{
		printf("Error while opening file.\n");//��������� �� ������
		exit(1);//�����
	}
	else//������� �������
	{
		while(!feof(filepointer))//���������� �� ����� �����
		{
			fscanf(filepointer,"%d ",&array[i]);//���������� ��������
			i++;//��������� ������� � �������
			*qty=*qty+1;//��������� ���������� ���������
		}
		fclose(filepointer);//�������� �����
	}
}

int checkn(int qty, int nmax,int *n)//�������� ���������� ���������
{
	while ((nmax<*n)||(*n<0))//���� �� ����� ������� ���������� �����
	{
		printf("This number is not allowed. Enter correct number: ");//���� ������� �����
		scanf("%d", &*n);
	}
}

int replace (int n,int *array)//������ ��������� � �������
{
	int i;//����������� ����������
	for (i = 1; i <= n; i++)//������ �� ���� ���������
	{
		array[0]=array[i];//�������� �������� � ������ ����������
		array[i]=array[i+n];//������ ��� ������ ���������
		array[i+n]=array[0];//������ ������� �������� ��������� �������
	}
}

int checkposnum(int qty, int *pos, int *num)//�������� ���������� ��������� � �������
{
	while ((*pos<=0)||(*pos>qty+1)||(((*pos+abs(*num))>(qty+1))&&(*num<0)))//���� �� ����� ������� ���������� �����
	{
		printf("Position must be from 1 to %d, sum of position and absolute change must not exceed %d in case of removing elements. Enter correct: ",qty+1,qty+1);//���� ������ �����
		scanf("%d %d", &*pos, &*num);
	}
}

int arrayinsert(int low, int up,int pos, int num, int *qty, int *array)//���������� ���������
{
	int i;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������
	stime=(unsigned) ltime/2;
	srand(stime);
	*qty=*qty+num;//��������� ���������� ���������
	*array=realloc(array,*qty*sizeof(int));//���������� �������
	for (i = (*qty-num); i >=pos ; i--)//����� ��������� � �����
	{
		array[i+num]=array[i];
	}
	for (i = pos; i <=pos+num-1; i++)//���������� ��������������� ����� ���������� �������
	{
		array[i]=low+(up-low)*rand()/RAND_MAX;
	}

}

int arraycutoff(int pos, int num, int *qty, int *array)//�������� ���������
{
	int i;//����������� ����������
	*qty=*qty+num;//��������� ���������� ���������
	for (i = pos; i <=pos+abs(num); i++)//����� ��������� � ������
	{
		array[i]=array[i+abs(num)];
	}

}

int checksize(int *arraysize)
{
	while (*arraysize<1)//���� �� ����� ������� ���������� �����
	{
		printf("Quantity of elements in array must be more than zero. Enter correct quantity: ");//���� ������� �����
		scanf("%d", &*arraysize);
	}

}

int sort(int qel, int *qas, int *qco, int *array)//���������� �������
{
	int k,j,i; //����������� ����������
	for (k = 2; k <=qel ; k++)//������ �� ���� ��������� ����� �������
	{
		array[0]=array[k];//�������� ������������� �������� � ������� �������
		*qas=*qas+1;//�������� ������������
		j=1;//����� ��������
		while((array[j]<array[0])&&(j<k))//������ �� ��������������� ���������
		{
			j++;//��������� ��������
			*qco=*qco+1;//�������� ���������
		}
		*qco=*qco+1;//�������� ���������
		for (i = k; i > j; i--)//���� ������ ��������
		{
			array[i]=array[i-1];//����� ��������
			*qas=*qas+1;//�������� ������������
		}
		array[j]=array[0];//������� �������� �� ��������
		*qas=*qas+1;//�������� ������������
	}
}

int sort1(int qel, int *qas, int *qco, int *array)//���������� �������
{
	int k,j,i,qsort=1,midel; //����������� ����������
	for (k = 2; k <=qel ; k++)//������ �� ���� ��������� ����� �������
	{
		array[0]=array[k];//�������� ������������� �������� � ������� �������
		*qas=*qas+1;//�������� ������������
		midel=qsort/2;
		if (midel==0)
		{
			midel=1;
		}
		if (array[0]>array[midel])
		{
			j=midel;
			while((array[j]<array[0])&&(j<k))//������ �� ��������������� ���������
			{
				j++;//��������� ��������
				*qco=*qco+1;//�������� ���������
			}
		}
		else
		{
			j=1;//����� ��������
			while((array[j]<array[0])&&(j<midel))//������ �� ��������������� ���������
			{
				j++;//��������� ��������
				*qco=*qco+1;//�������� ���������
			}
		}
		*qco=*qco+2;//�������� ���������
		for (i = k; i > j; i--)//���� ������ ��������
		{
			array[i]=array[i-1];//����� ��������
			*qas=*qas+1;//�������� ������������
		}
		array[j]=array[0];//������� �������� �� ��������
		*qas=*qas+1;//�������� ������������
		qsort++;
	}
}

int sortn(int qel, int *qas, int *qco, int *array)//���������� �������
{
	int l,k,j,i,qsort=2,poss=1,pose=qsort; //����������� ����������
	for (k = 2; k <=qel ; k++)//������ �� ���� ��������� ����� �������
	{
		array[0]=array[k];//�������� ������������� �������� � ������� �������
		*qas=*qas+1;//�������� ������������
		for (l = 0; l <= (log10(qsort)/log10(2)+0.5); l++)//���������� �������
		{
			if (array[0]>array[poss+(pose-poss)/2])//������� ���������
			{
				poss=poss+(pose-poss)/2;//��������� ������
			}
			else
			{
				pose=poss+(pose-poss)/2;//��������� �����
			}
			*qco=*qco+1;
		}
		if (qsort==1)//������������� ��� ������� ��������
		{
			j=pose;
			qsort++;
			poss=1;
			if (array[0]<array[1])
			{
				array[2]=array[1];
				array[1]=array[0];
			}
			*qco=*qco+1;
			*qas=*qas+2;
		}
		else
		{
			j=pose;
			qsort++;
			poss=1;
			pose=qsort;
			for (i = k; i > j; i--)//���� ������ ��������
			{
				array[i]=array[i-1];//����� ��������
				*qas=*qas+1;//�������� ������������
			}
			array[j]=array[0];//������� �������� �� ��������
		}
		*qas=*qas+1;//�������� ������������

	}
}

int QuickSort(int first, int last, int *array)
{
int pivot; /*������� ��������*/
int l,r; /*����� � ������ ��������*/
l=first; r=last;
pivot=array[(l+r)/2]; /*����������� �������� ��������*/
while (l<=r) {
while (array[l]<pivot) l++;
while (array[r]>pivot) r--;
if (l<=r) {
swap(&array[l],&array[r]); /*������������ ���� ���������*/
l++;
r--;
}
} /*����������� ����������:*/
if (first<r) QuickSort(first,r,array); /*- ������ �������, */
if (l<last) QuickSort(l,last,array); /*- ������� �������.*/
}
int swap(int *x, int *y)
{
int temp; /* temp - ��������������� ���������� */
temp=*x;
*x=*y;
*y=temp;
}
