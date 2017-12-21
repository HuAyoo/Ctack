#include <stdio.h>
#include<string.h>
extern void storage(void);
extern void tset(void);
extern void bin_mif_create(void);
int main()
{
	storage();
	tset();
	//每次更新要删除生成的文件。
	bin_mif_create();
	printf("*****END!******\n");
}