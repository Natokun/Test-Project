/*����һ����̬����*/ 

#include <stdio.h>
#include <stdlib.h>


struct list
{
	int *i;	//����
	int n;	//��
	int max;	//�����ֵ
};

struct list *CreatList(int n);	//�����վ�̬����
void InsistList(struct list *L, int i, int n);	//����Ԫ��
void PrintList(struct list *L, int i);	//�������Ԫ��
void ScanList(struct list *L, int i, int n);	//���ı���Ԫ��
void DeleteList(struct list *L, int n);	//ɾ��Ԫ��
void FindList(struct list *L,int i);	//��������i�ڱ�����ﲢ���
void PositionList(struct list *L,int n);	//����λ��n�ڵ�����
void SwapList(struct list *L,int n1,int n2);	//����n1��n2������
void FastSortList(struct list *L, int f,int r);	//��������


int main()
{
	struct list *L;
	int i=0;
	int N;
	
	scanf("%d",&N);
	if(N<=3)
	{
		printf("we don't need that!\n");
		return 0;
	}
	L=CreatList(N);
	int n=0;

	while(n<N)
	{	
		scanf("%d",&i);
		InsistList(L,i,n);
		n++;
	}
	n=0;
	while(n<L->n)
	{
		if(n==0) printf("Inital List: ");
		PrintList(L,n);
		printf(" ");
		if(n==N-1) printf("\n");
		n++;
	}
	printf("%d\n",L->n-1);
	FastSortList(L,0,L->n-1);
	n=0;
	while(n<L->n)
	{
		if(n==0) printf("Current List: ");
		PrintList(L,n);
		printf(" ");
		if(n==N-1) printf("\n");
		n++;
	}
	return 0;
};

void FastSortList(struct list *L, int f, int r)	//��������
{
	if(f>=r) return;
	int a=f;
	int b=r;
	int X=L->i[r/3+a];
	int n=0;
	SwapList(L,f,r/3+a);
	printf("X=%d,a=%d,b=%d\n",X,a,b);
	while(n<L->n)
	{
		if(n==0) printf("1st Temporary List: ");
		PrintList(L,n);
		printf(" ");
		if(n==L->n-1) printf("\n");
		n++;
	}
	while(a<b)
	{
		while(a<b && L->i[b]>=X) b--;
		if(a<b)
		{
			L->i[a]=L->i[b];
			a++;
		}
		while(a<b && L->i[a]<X) a++;
		if(a<b)
		{
			L->i[b]=L->i[a];
			b--;
		}
		if(a>=b) break;
	}
	L->i[a]=X;
	n=0;
	while(n<L->n)
	{
		if(n==0) printf("2nd Temporary List: ");
		PrintList(L,n);
		printf(" ");
		if(n==L->n-1) printf("\n");
		n++;
	}
	printf("f=%d,r=%d,a=%d,b=%d\n",f,r,a,b);
	FastSortList(L,f,a-1);
	FastSortList(L,b+1,r);
}

struct list *CreatList(int n)
{
	struct list *L=(struct list *)malloc(sizeof(struct list));
	L->i=(int*)malloc(n*sizeof(int));
	L->n=0;
	L->max=n;
	return L;
};

void InsistList(struct list *L, int i, int n)	//����Ԫ��
{
	if(n<0 || n>L->n || L->n==L->max)
	{
		printf("Insist ERROR!\n");
		return;
	}
	if(n==L->n+1)
	{
		n++;
		L->i[n]=n;
	}
	else
	{
		int j=L->n-1;
		while(j>=n)
		{
			L->i[j+1]=L->i[j];
			j--;
		}
		L->i[j+1]=i;
		L->n++;
	}
}

void PrintList(struct list *L, int i)	//�������Ԫ��
{
	if(i>=L->n)
	{
		printf("Print ERROR!\n");
		return;
	}
	printf("%d",L->i[i]);
}

void ScanList(struct list *L, int i, int n)	//���ı���Ԫ��
{
	if(n<0 || n>L->n-1 || L->n==L->max)
	{
		printf("Scan ERROR!\n");
		return;
	}
	L->i[n]=i;
}

void DeleteList(struct list *L, int n)	//ɾ��Ԫ��
{
	if(n<0 || n>L->n-1)
	{
		printf("Delete ERROR!\n");
		return;
	}
	int j=n;
	while(j<L->n)
	{
		L->i[j]=L->i[j+1];
		j++;
	}
	L->n--;
}

void FindList(struct list *L,int i)	//��������i�ڱ�����ﲢ���
{
	int j=0;
	while( L->i[j]!=i && j<L->n)
	{
		j++;
	}
	if( j==L->n )
	{
		printf("The number is not in the List.\n");
	}
	else
	{
		printf("The %d is in the position %d.\n",i,j);
	}
}

void PositionList(struct list *L,int n)	//����λ��n�ڵ�����
{
	if(n<0 || n>L->n-1)
	{
		printf("Position ERROR!\n");
		return;
	}
	printf("There is %d in the position %d.\n",L->i[n],n);
}

void SwapList(struct list *L,int n1,int n2)	//����n1��n2������
{
	if(n1<0 || n1>L->n-1 || n2<0 || n2>L->n-1)
	{
		printf("Swap ERROR!\n");
		return;
	}
	int temp;
	temp=L->i[n1];
	L->i[n1]=L->i[n2];
	L->i[n2]=temp;
}

//���Բ�����������
