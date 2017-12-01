#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int **alloc2d(int,int);
void gray_r(int **,int,int,int);
void printmat(int **,int,int);
int main(int argc,char *argv[])
{
    int row,col;
    int **mat;
    printf("Insert number of bits:\n");
    scanf("%d",&col);
    row=pow(2,col);
    mat=alloc2d(row,col);
    gray_r(mat,row,col,0);
    printmat(mat,row,col);
    return 0;
}
int **alloc2d(int r,int c)
{
    int **mat;
    int i;
    mat=(int **)malloc(r*sizeof(int *));
    if(mat==NULL)
    {
        printf("error in row allocation!\n");
        exit(0);
    }
    for(i=0; i<r; i++)
    {
        mat[i]=(int *)malloc(c*sizeof(int));
        if(mat[i]==NULL)
        {
            printf("error in row allocation!\n");
            exit(0);
        }
    }
    return mat;
}
void gray_r(int **mat,int row,int col,int level){
    int reflect;
    int r,c;
    if(level>=col){
        return;
    }
    reflect=pow(2,level);
    for(c=0;c<level;c++){
        for(r=0;r<reflect;r++){
            mat[2*reflect-r-1][col-c-1]=mat[r][col-c-1];
        }
    }
    for(r=0;r<reflect;r++){
        mat[r][col-level-1]=0;
        mat[reflect+r][col-level-1]=1;
    }
    gray_r(mat,row,col,level+1);
    return;
}
void printmat(int **mat,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
