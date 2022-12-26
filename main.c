#include <stdio.h>
#include <stdlib.h>

void Task_1();
void Task_2();
void Task_3();
void PrintMatrix(int ** matrix,int Arows);
//-----------------------------
int main()
{
    srand(time(0));
    printf("Chose task(1-3):");
    int var=0;
    while(var<1||var>3)
    {
        scanf("%d",&var);
    }
    switch(var)
    {
    case 1:
        Task_1();
        break;
    case 2:
        Task_2();
        break;
    case 3:
        Task_3();
        break;

    }
}
void PrintMatrix(int ** matrix,int Arows)
{
    printf("\n--------------------\n");
    for(int i=0;i<Arows;i++)
    {
        printf("|");
        for(int j=0;j<Arows;j++)
        {
            printf("%d|",matrix[i][j]);
        }
        printf("\n--------------------\n");
    }
}
//-----------------------------
void Task_1()
{
    float sum=0,a=0;
    int N=-1;
    printf("Enter N(N>=0):");
    while(N<0)
    {
        scanf("%d",&N);
    }
    printf("Enter a:");
    scanf("%f",&a);
    for(int i=0;i<=N;i++)
    {
        int var=1;
        float temp=1;
        if(i%2!=0)
        {
            temp=-1;
        }
        for(int j=1;j<=2*i+1;j++)
        {
            var=var*j;
            temp=temp*a;
        }
        temp=temp/var;
        sum+=temp;
    }
    printf("%f",sum);
}
void Task_2()
{
    int** A;
    int** B;
    int Arows=0;
    printf("Enter the size of the array(1-10):");
    while(Arows<1||Arows>10)
    {
        scanf("%d", &Arows);
    }
    int* Temp;
    int* Fin;
    Temp=(int*)calloc(Arows*Arows, sizeof(int));
    Fin=(int*)calloc(Arows*Arows, sizeof(int));
    A=(int**)calloc(Arows, sizeof(int*));
    B=(int**)calloc(Arows, sizeof(int*));
    if(A==NULL||B==NULL||Temp==NULL||Fin==NULL)
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i=0;i<Arows;i++)
    {
        A[i]=(int*)calloc(Arows, sizeof(int));
        B[i]=(int*)calloc(Arows, sizeof(int));
        if(A[i]==NULL||B[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    int a;
    a=rand()%10+1;
    for(int i=0;i<Arows;i++)
    {
        for(int j=0;j<Arows;j++)
        {
            A[i][j]=rand()%(2*a+1)-a;
            B[i][j]=0;
        }
    }
    printf("Matrix A:");
    PrintMatrix(A,Arows);
    for(int i=0,k=0;i<Arows;i++)
    {
        for(int j=0;j<Arows;j++,k++)
        {
            Temp[k]=A[i][j];
            Fin[k]=0;
        }
    }
    for(int i=0;i<Arows*Arows;i++)
    {
        int sum=0;
        for(int j=0;j<Arows*Arows;j++)
        {
            if(i!=j)
            {
                sum+=Temp[j];
            }

        }
        Fin[i]=sum;
    }
    for(int i=0,k=0;i<Arows;i++)
    {
        for(int j=0;j<Arows;j++,k++)
        {
            B[i][j]=Fin[k];
        }
    }
    printf("\nMatrix B:");
    PrintMatrix(B,Arows);
    for (int i = 0; i < Arows; i++)
    {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);
    free(Temp);
    free(Fin);
}
void Task_3()
{
    FILE* input_F = fopen ("Input.txt", "r");
    if (input_F==NULL)
    {
        printf("The file couldn`t be open");
    }
    else
    {
        fseek(input_F, 0, SEEK_END);
        int length = ftell(input_F);
        fseek(input_F, 0, SEEK_SET);
        int count=0;
        for(int i=0;i<length;i++)
        {
            char ch;
            ch = fgetc(input_F);
            if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'||ch=='y'||ch=='Y')
            {
                count++;
            }
        }
        fclose(input_F);
        printf("\nCount:%d",count);
    }

}
