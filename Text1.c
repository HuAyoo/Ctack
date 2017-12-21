#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#define PI 3.141592
#define DEPTH 8192     /*数据深度，即存储单元的个数*/
#define WIDTH 16       /*存储单元的宽度*/

int out[2];//每次写4个字节
void out_bin(unsigned int b);
void out_MIF(void);

void bin_mif_create(void)
{
	int j;
	float  pi_2 = 6.283185;//设置pi值
	float average = pi_2 /DEPTH,ff;
	unsigned int outvalue;
	out_MIF();
	for (j = 0; j<DEPTH;j++)//8192ge
	{
		ff = (sin(average*j)+1)*4096/2;	//12位da
		outvalue = (unsigned int)ff;
		out_bin(outvalue);//输出bin
		printf("%d  \n",outvalue);
	}

	printf("run over!\n");
}
void out_bin(unsigned int b)
{
    int j,i,a[4];  
	FILE *fp;
	fp = fopen("Text2.bin","a+b");

    for(j=0; j<4; j++)  //796
    {  
        i=b%16;  
        a[j]=i;  
     
        b=b/16;  
    }  
	out[1 ] = a[0]|(a[1]<<4);//0x1c
	out[0] = (a[2]|(a[3]<<4))|(out[1]<<8);//0x031c
	fwrite(out,2,1,fp);//

		fclose(fp);
}
void out_MIF(void)
{
	int i,temp;
	float s;
    FILE *fp;
    fp = fopen("TestMif.mif","w");   /*文件名随意，但扩展名必须为.mif*/
    if(NULL==fp)
        printf("Can not creat file!\r\n");
    else
    {
        printf("File created successfully!\n");
        /**生成文件头：注意不要忘了“;”*/
        fprintf(fp,"DEPTH = %d;\n",DEPTH);
        fprintf(fp,"WIDTH = %d;\n",WIDTH);
        fprintf(fp,"ADDRESS_RADIX = HEX;\n");
        fprintf(fp,"DATA_RADIX = HEX;\n");
        fprintf(fp,"CONTENT\n");
        fprintf(fp,"BEGIN\n");

        /** 以十六进制输出地址和数据*/
        for(i=0;i<DEPTH;i++)
        {
            //周期为8192个点的正弦波
            s = sin(PI*2/DEPTH*i);   

           //将-1～1之间的正弦波的值扩展到0-255之间
            temp = (unsigned int)((s+1)*4095/2);
            //以十六进制输出地址和数据

        fprintf(fp,"%x\t:\t%x;\n",i,temp);

        }
        
        fprintf(fp,"END;\n");
        fclose(fp);
    }

}