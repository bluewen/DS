#include"SEQ_LIST.h"
#include<stdlib.h>
#include<stdio.h>

void int_print(void *e)
{
	printf("%d ", *(int *)e);
}

void double_print(void *e)
{
	printf("%lf ", *(double *)e);
}


int main()
{
	SEQLIST seq1;
	SEQLIST seq2;
	SEQLIST seq;
	
	InitSeqlist(&seq1);
	InitSeqlist(&seq2);
	InitSeqlist(&seq);
	/*for (int i = 0; i < 20; i++)
	{
		InsertHead(&seq, 1 * i);
	}

	
	
	for (int i = 0; i < 10; i++)
	{
		InsertTail(&seq1, i * 10);

	}

	for (int i = 0; i < 1; i++)
	{
		InsertTail(&seq2, i * 10);

	}

	unio(&seq1, &seq2);

	DispalyEx(&seq1, int_print);
	
	printf("\n");
	
	DispalyEx(&seq2, int_print);
	*/


	InsertTail(&seq1, 3);
	InsertTail(&seq1, 5);
	InsertTail(&seq1, 8);
	InsertTail(&seq1, 11);
	InsertTail(&seq2, 1);
	InsertTail(&seq2, 2);
	InsertTail(&seq2, 6); 
	InsertTail(&seq2, 8);
	InsertTail(&seq2, 9);
	InsertTail(&seq2, 11);
	

    MergeList( &seq1,&seq2,&seq);

	DispalyEx(&seq, int_print);
	//printf("%d ", Max(&seq));
	//printf("%d ", Min(&seq));
	//printf("%d ", IsFull(&seq));
	
	return 0;
}