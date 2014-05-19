#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bigint
{
	unsigned int* hms;
	unsigned int size;
	char sign;
} bigint;

unsigned int min(unsigned int i1, unsigned int i2)
{
	if (i1>=i2) return i2;
	return i1;
}

unsigned int max(unsigned int i1, unsigned int i2)
{
	if (i1>=i2) return i1;
	return i2;
}
void biClear(bigint* bi)
{
	int j = 0;
	for (;j<bi->size;j++)
	{
		bi->hms[j] = 0;
	}
}
void biPrint(bigint* bi)
{
	int i = bi->size - 1;
	char foundNon0 = 0;
	for (;i>=0;i--)
	{
		if (bi->hms[i] != 0) foundNon0 = 1;
		if (foundNon0) printf("%i", bi->hms[i]);
	}
	if (!foundNon0) printf("0");
}
char biCompar(bigint* i1, bigint* i2) // 1 means i1 > i2
{
	bigint* in1;
	bigint* in2;
	if (i1->size >= i2->size){in1=i1;in2=i2;}
	else{in1=i2;in2=i1;}
	int i = in1->size-1;
	for (;i>=in2->size;i--)
	{
		if (in1->hms[i] != 0) return 1;
	}
	for (;i>=0;i--)
	{
		if (in1->hms[i] > in2->hms[i]) return 1;
		else if (in1->hms[i] < in2->hms[i]) return -1;
	}
	return 0;
}
bigint biCreate(int i)
{
	bigint bi;
	bi.size = 4;
	bi.hms = malloc(sizeof(&bi.hms)*bi.size);
	biClear(&bi);
	     if (i< 0) bi.sign = -1;
	else if (i==0) bi.sign =  1;
	else if (i> 0) bi.sign =  1;
	if (i<0) i = -i;
	bi.hms[0] = i;
}
bigint biCreateSize(int size)
{
	bigint bi;
	bi.size = size;
	bi.hms = malloc(sizeof(&bi.hms)*bi.size);
	biClear(&bi);
	bi.sign =  1;
	return bi;
}
bigint biFromString(char* str)
{
	bigint bi;
	bi.size = strlen(str)/4+4;
	bi.hms = malloc(sizeof(&bi.hms)*bi.size);
	biClear(&bi);
	if (str[0]=='-')
	{
		bi.sign = -1;
		str++;
	}
	else bi.sign = 1;
	int l = strlen(str);
	int i = l-8;
	char replacedBy0 = -1;
	unsigned int pow = 0;
	for (;i>=-7;i-=8)
	{
		if (1)//i>0)
		{
			replacedBy0 = str[i+8];
			if (replacedBy0!=0) str[i+8] = '\0';
		}
		if (i<=0)
		{
			printf("str=%s\n", str);
			bi.hms[pow] = atoi(str);
			return bi;
		}
		else
		{
			printf("str=%s\n", &str[i]);
			bi.hms[pow] = atoi(&str[i]);
		}
		if (1)//i>0)
		{
			if (replacedBy0!=0) str[i+8] = replacedBy0;
		}
		pow++;
	}
	return bi;
}

bigint biCopy(bigint* in)
{
	bigint bi;
	bi.size = in->size;
	bi.sign = in->sign;
	bi.hms = malloc(sizeof(&bi.hms)*bi.size);
	memcpy(bi.hms, in->hms, bi.size);
	return bi;
}

bigint biExpand(bigint in, int ints)
{
	// TODO
}
bigint biAdd(bigint* n1, bigint* n2)
{
	bigint bi;
	bigint* add;
	if (n1->size >= n2->size){bi=biCopy(n1);add=n2;}
	else{bi=biCopy(n2);add=n1;}
	int i = 0; char carry = 0;
	for (;i<bi.size;i++)
	{
		if (i<add->size) bi.hms[i] += add->hms[i];
		bi.hms[i] += carry;
		if (bi.hms[i]>=100*1000*1000)
		{
			bi.hms[i] -= 100*1000*1000;
			carry = 1;
		}
		else carry = 0;
	}
	return bi;
}
bigint biMul(bigint* n1, bigint* n2)
{
	bigint bi     = biCreateSize(n1->size + n2->size + 2);
	bigint tempBi = biCreateSize(n1->size + n2->size + 2);
	int i = 0;
	for (;i<n1->size;i++)
	{
		int j = 0;
		for (;j<n2->size;j++)
		{
			unsigned long tempL = (unsigned long)n1->hms[i] * (unsigned long)n2->hms[j];
			printf("%i * %i = %lu\n", n1->hms[i], n2->hms[j], tempL);
			if (tempL==0) continue;
			unsigned int n1 = tempL % (100*1000*1000); // small
			unsigned int n2 = tempL / (100*1000*1000); // big
			biClear(&tempBi);
			tempBi.hms[i+j] = n1;
			tempBi.hms[i+j+1] = n2;
			bi = biAdd(&bi, &tempBi);
		}
	}
	return bi;
}

int main()
{
	char str[] = "123432123";
	bigint i1 = biFromString(&str[0]);
	
	//char str2[] = "123";
	bigint i2 = biCopy(&i1);//biFromString(&str2[0]);
	
	biPrint(&i1);
	printf("\n");
	
	biPrint(&i2);
	printf("\n");
	
	bigint bi = biMul(&i1, &i2);
	
	//biPrint(&bi);
	//printf("\n");
	
	printf("[0]=%u\n", bi.hms[0]);
	printf("[1]=%u\n", bi.hms[1]);
	printf("[2]=%u\n", bi.hms[2]);
	printf("[3]=%u\n", bi.hms[3]);
	printf("[4]=%u\n", bi.hms[4]);
	return 0;
}
