#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	int t[99][99]={0};
	int n, i, j, k, c, d, count;
	FILE  *ofp;
	ofp = fopen("output_a.txt" , "w");//答案會寫進output_a.txt
	count=0;//為了最後結果換行需要
	n = 99;
	i=0;
	j=49;
	t[i][j] = 1;//第一列最中間放起始值1
    
	for(k=2;k<=9801;k++){
		if(i-1>=0 && i-1<n && j+1>=0 && j+1<n && t[i-1][j+1]==0)//右上位置列與行都在裡面 且 尚未填入值
		{
			t[i-1][j+1]=k;
			i=i-1;
			j=j+1;
		}
		else if (i-1<0 && j+1<n )//右上位置落在第一列的上面 將值填入最後一列
		{
			t[n-1][j+1]=k;
			i=n-1;
			j=j+1;
		}
		else if (i-1<n && i-1>=0 && j+1>=n )//右上位置落在最後一行 將值填入第一行
		{
			t[i-1][0]=k;
			i=i-1;
			j=0;
		}
		else if (i-1>=0 && i-1<n && j+1>=0 && j+1<n && t[i-1][j+1]>0)//右上位置已被其他值先填入 將值填入原位置的下方
		{
			t[i+1][j]=k;
			i=i+1;
		}
		else if (i-1<0 && j+1>=n)//右上位置列與行都在外面 將值填入原位置的下方
		{
			t[i+1][j]=k;
			i=i+1;
		}
	}
		
	for(c=0;c<99;c++)
	    for(d=0;d<99;d++){
	    	printf("%5d",t[c][d]);
	    	count++;//使用count來計數 列印到第99個值代表第一列列印完 列印換行(\n)
	        if (count%99==0)
	        {
	        	printf("\n");
	        }
	    }

	for(c=0;c<99;c++){
	    for(d=0;d<99;d++){
	    	fprintf(ofp,"%5d",t[c][d]);//格式化輸入到檔案
	    	count++;
	        if (count%99==0)
	        {
	        	putc('\n',ofp);
	        }
	    }
	}
	fclose(ofp);//檔案關閉
}