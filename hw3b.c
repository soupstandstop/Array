#include<stdio.h> 
#include<stdlib.h>
int main(int argc, char *argv[]){
	int i, j, k, c, d, n, count;FILE  *ofp;
	ofp = fopen("output_b.txt" , "w");//答案會寫進output_b.txt
	count = 0;n = atoi(argv[1]);
    int *t2 = NULL;
    t2 = (int*)malloc(sizeof(int)*n*n);
    for (int i = 0; i < n*n; ++i)
    {t2[i] = 0;}
    t2[n/2] = 1;//第一列最中間放起始值1
    i = n/2;
    for(k=2;k<=n*n;k++)
		if((i-(n-1)>=0) && (i-(n-1)<n*n) && t2[i-(n-1)]==0 && (i-(n-1))%n !=0)//右上位置列與行都在裡面 且 尚未填入值
		{
			t2[i-(n-1)]=k;
			i=i-(n-1);
		}
		else if ((i-(n-1)>=0) && (i-(n-1)<n*n) && t2[i-(n-1)]!=0 && (i-(n-1))%n !=0)//右上位置已被其他值先填入 將值填入原位置的下方
		{
			t2[i+n]=k;
			i=i+n;
		}
		else if (i-(n-1)<0 && i!=n-1)//右上位置落在第一列的上面 將值填入最後一列
		{
			t2[n*(n-1)+i+1]=k;
			i=n*(n-1)+i+1;
		}
		else if ((i-(n-1))%n==0 && i!=n-1)//右上位置落在最後一行的右邊 將值填入第一行
		{
			t2[i-n-(n-1)]=k;
			i=i-n-(n-1);
		}
		else if (i-(n-1)<=0 && i==n-1)//右上位置列與行都在外面 將值填入原位置的下方
		{
			t2[i+n]=k;
			i=i+n;
		}
	for(c=0;c<n*n;c++){
		printf("%5d",t2[c]); count++;
	    if (count%n == 0)
	       {
	        printf("\n");
	       }}
	for(c=0;c<n*n;c++){
		fprintf(ofp,"%5d",t2[c]);
	    count++;
	    if (count%n == 0)
	       {
	        putc('\n',ofp);
	       }}
	fclose(ofp);//檔案關閉    
	free(t2);
	return 0;
}
