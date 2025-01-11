#include<stdio.h>
#include<string.h>

int find_index(char *input1,char *input2,int size1,int size2)
{
    int index=-1;
    for(int itr=0;itr<size1;itr++)
    {
       if(input1[itr]==input2[0])
       {
        int itr2=0;
        int temp_itr=itr;
        while(input1[temp_itr]==input2[itr2] && input2[itr2]!='\0')
        {
            temp_itr++;
            itr2++;
        }
            if(input2[itr2]=='\0')
            {
             index= itr;
             break;
            }
        }
    }
    return index;
}

int main()
{
    char input1[100],input2[100];
    fgets(input1,sizeof(input1),stdin);
    fgets(input2,sizeof(input2),stdin);
    int size1=strlen(input1);
    int size2=strlen(input2);
    if(size1>0 && input1[size1-1]=='\n')
    {
    input1[size1-1]='\0';
    }
    if(size2>0 && input2[size2-1]=='\n')
    {
    input2[size2-1]='\0';
    }
    int index=find_index(input1,input2,size1,size2);
    printf("%d",index);
    return -1;
}