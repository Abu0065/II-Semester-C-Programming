#include<stdio.h>
#define MAX 100

int main(){
    int A[MAX][MAX],B[MAX][MAX],R[MAX][MAX],T[MAX][MAX];
    int rA,cA,rB,cB;
    scanf("%d%d",&rA,&cA); 
    for(int i=0;i<rA;i++) for(int j=0;j<cA;j++) scanf("%d",&A[i][j]);
    scanf("%d%d",&rB,&cB); 
    for(int i=0;i<rB;i++) for(int j=0;j<cB;j++) scanf("%d",&B[i][j]);

    if(rA==rB&&cA==cB){
        for(int i=0;i<rA;i++){for(int j=0;j<cA;j++) printf("%d ",A[i][j]+B[i][j]); printf("\n");}
        for(int i=0;i<rA;i++){for(int j=0;j<cA;j++) printf("%d ",A[i][j]-B[i][j]); printf("\n");}
    }
    if(cA==rB){
        for(int i=0;i<rA;i++){for(int j=0;j<cB;j++){R[i][j]=0;for(int k=0;k<cA;k++)R[i][j]+=A[i][k]*B[k][j];printf("%d ",R[i][j]);}printf("\n");}
    }
    for(int i=0;i<rA;i++){for(int j=0;j<cA;j++)T[j][i]=A[i][j];}
    for(int i=0;i<cA;i++){for(int j=0;j<rA;j++)printf("%d ",T[i][j]);printf("\n");}
}