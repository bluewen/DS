#include"SEQ_LIST.h"
#include<stdlib.h>
#include<stdio.h>


bool InitSeqlist(SEQLIST *p)
{
	if (p == NULL)
	{
		return false;
	}

	p->length = 0;
	return true;
}

bool ClearSeqlist(SEQLIST *p)
{
	if (p == NULL)
	{
		return false;
	}

	p->length = 0;
	return true;
}

bool IsFull(SEQLIST *p)
{
	if (p == NULL)
	{
		return false;
	}

	return p->length == MAXSIZE;
}

bool IsEmpty(SEQLIST *p)
{
	if (p == NULL)
	{
		return false;
	}

	return p->length == 0;
}

int Getlength(SEQLIST *p)
{
	if (p == NULL)
	{
		return ERROR;
	}

	return p->length;
}

bool GetElemByPos(SEQLIST *p, int pos, elemtype *e)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int len = Getlength(p);
	if (pos < 0 || pos >= len)
	{
		return false;
	}

	*e = p->data[pos];

	return true;

}

int GetPosByElem(SEQLIST *p, elemtype v)
{
	if (p == NULL || IsEmpty(p))
	{
		return ERROR;
	}

	int len = Getlength(p);
	for (int i = 0; i < len; i++)
	{
		if (p->data[i] == v)
		{
			return i;
		}
	}

	return ERROR;

}

bool Getprio(SEQLIST *p, elemtype v, elemtype *e)
{
	
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int pos = GetPosByElem(p, v);
	if (pos <= 0 || pos > Getlength(p) - 1)
	{
		return false;
	}

	int rpos = pos - 1;
	*e = p->data[rpos];

	return true;
}

bool GetNext(SEQLIST *p, elemtype v, elemtype *e)
{
	
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int pos = GetPosByElem(p, v);
	if (pos < 0 || pos >= Getlength(p) - 1)
	{
		return false;
	}

	int rpos = pos + 1;
	*e = p->data[rpos];

	return true;

}

bool SetElem(SEQLIST *p, int pos, elemtype v)
{
	if (p == NULL || pos < 0 || pos >= Getlength(p) || IsEmpty(p))
	{
		return false;
	}

	p->data[pos] = v;

	return true;
}

bool InsertHead(SEQLIST *p, elemtype v)
{
	if (p == NULL || IsFull(p))
	{
		return false;
	}
	
	int i = Getlength(p)-1;

	for (; i >= 0; i--)
	{
		p->data[i + 1] = p->data[i];
	}
	p->data[0] = v;
	p->length++;//注意

	return true;
}

bool InsertTail(SEQLIST *p, elemtype v)
{
	if (p == NULL || IsFull(p))
	{
		return false;
	}

	int len = Getlength(p);
	p->data[len] = v;
	p->length++;//

	return true;
}

bool DeleteHead(SEQLIST *p, elemtype *e)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int len = Getlength(p);

	*e = p->data[0];

	for (int i = 1; i < len; i++)
	{
		p->data[i - 1] = p->data[i];
	}
	p->length--;//注意

	return true;

}

bool DeleteTail(SEQLIST *p, elemtype *e)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	*e = p->data[0];

	p->length--;//
	return true;

}

bool Insert(SEQLIST *p, int pos, elemtype v)
{
	if (p == NULL || IsFull(p))
	{
		return false;
	}

	int len = Getlength(p);

	if (pos<0 || pos>len)
	{
		return false;
	}

	for (int i = len - 1; i >= pos;i--)
	{
		p->data[i + 1] = p->data[i];
	}

	p->data[pos] = v;
	p->length++;//注意

	return true;
}
	
bool Delete(SEQLIST *p, int pos, elemtype *e)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int len = Getlength(p);

	if (pos<0 || pos>=len)
	{
		return false;
	}

	*e = p->data[pos];

	for (int i = pos; i < len-1; i++)
	{
		p->data[i] = p->data[i + 1];
	}

	p->length--;//注意
	return true;
}

bool DispalyEx(SEQLIST *p, void(*pfunc)(void*))
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int len = Getlength(p);

	for (int i = 0; i < len; i++)
	{
		pfunc(&p->data[i]);
	}

	return true;
}



bool Display(SEQLIST *p)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int len = Getlength(p);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", p->data[i]);
	}

	return true;
}

int Max(SEQLIST *p)
{
	if (p == NULL || IsEmpty(p))
	{
		return ERROR;
	}

	int Max = p->data[0];
	int len = Getlength(p);

	for (int i = 1; i < len; i++)
	{
		if (p->data[i] > Max)
		{
			Max = p->data[i];
		}
	}

	return Max;
}


int Min(SEQLIST *p)
{
	if (p == NULL || IsEmpty(p))
	{
		return ERROR;
	}

	int Min = p->data[0];
	int len = Getlength(p);

	for (int i = 1; i < len; i++)
	{
		if (p->data[i] < Min)
		{
			Min = p->data[i];
		}
	}

	return Min;
}


bool sort(SEQLIST *p)
{
	if (p == NULL || IsEmpty(p))
	{
		return false;
	}

	int tmp;
	int len = Getlength(p);

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (p->data[j]>p->data[j + 1])
			{
				tmp = p->data[j];
				p->data[j] = p->data[j + 1];
				p->data[j + 1] = tmp;
			}
		}
	}

	return true;
}



bool unio(SEQLIST *p1, SEQLIST *p2)
{

	if (p1 == NULL || p2 == NULL)
	{
		return false;
	}

	int e = 0;
	int e1 = 0;
	int e2 = 0;

	for (int i = 0; i < p1->length; i++)
	{
		GetElemByPos(p1, i, &e1);
		for (int j = 0; j < p2->length; j++)
		{
			GetElemByPos(p2, j, &e2);
			if (e1 == e2)
			{
				Delete(p1, i, &e);
				i--;
				break;
			}
		}

	}



	return true;

}




bool MergeList(SEQLIST *p1, SEQLIST *p2, SEQLIST *p)
{
	if (p1 == NULL || p2 == NULL)
	{
		return false;
	}

	int i = 0;
	int j = 0;
	int k = 0;
	int e = 0;
	int e1 = 0;
	int e2 = 0;

	

	while (i < p1->length && j < p2->length)
	{
		GetElemByPos(p1, i, &e1);
		GetElemByPos(p2, j, &e2);

		if (e1 <= e2 )
		{ 
			Insert(p, k, e1);
			i++;
			k++;
		}
		else
		{
			Insert(p, k, e2);
			j++;
			k++;
		}

		
	}
	
	while (i < p1->length)
	{
		GetElemByPos(p1, i, &e1);
		Insert(p, k, e1);
		i++;
		k++;
	}

	while (j < p2->length)
	{
		GetElemByPos(p2, j, &e2);
		Insert(p, k, e2);
		j++;
		k++;
	}



}