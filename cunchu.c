#include <stdio.h>
#include<string.h>
extern void storage(void);
extern void tset(void);
extern void bin_mif_create(void);
int main()
{
	storage();
	tset();
	//ÿ�θ���Ҫɾ�����ɵ��ļ���
	bin_mif_create();
	printf("*****END!******\n");
}