#include<stdio.h>
 
int arr[5][5],completed[5],n,cost=0;
 
void getInput()
{
    int i,j;
 
    printf("input number of city : ");
    scanf("%d",&n);
 
    printf("\ninput cost array \n");
 
    for(i=0;i < n;i++)
    {
        printf("\ninput Elements of Row: %d\n",i+1);
        
        for( j=0;j < n;j++)
            scanf("%d",&arr[i][j]);
        
        completed[i]=0;
    }
}
int least(int c)
{
    int i,nc=999;
    int min=999,arr_min;
    
    for(i=0;i < n;i++)
    {
        if((arr[c][i]!=0)&&(completed[i]==0))
            if(arr[c][i]+arr[i][c] < min)
            {
                min=arr[i][0]+arr[c][i];
                arr_min=arr[c][i];
                nc=i;
            }
    }
 
    if(min!=999)
        cost+=arr_min; 
return nc;
}
 
void getMinCost(int city)
{
    int i,ncity;
    
    completed[city]=1;
    
    printf("%d--->",city+1);
    ncity=least(city);
    
    if(ncity==999)
    {
        ncity=0;
        printf("%d",ncity+1);
        cost+=arr[city][ncity];
    
    return;
    }
 
    getMinCost(ncity);
}
 
int main()
{
    getInput();
 
    printf("\n\nThe Path is:\n");
    getMinCost(0); 
    printf("\n\nMinimum cost is %d\n ",cost);
 
    return 0;
}