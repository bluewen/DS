#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define MAXSIZE 10
#define ERROR -1

typedef int elemtype;

typedef struct _SEQLIST
{
	elemtype data[MAXSIZE];
	int length;

}SEQLIST;

bool InitSeqlist(SEQLIST *p);
bool ClearSeqlist(SEQLIST *p);

bool IsFull(SEQLIST *p);
bool IsEmpty(SEQLIST *p);

int Getlength(SEQLIST *p);

bool GetElemByPos(SEQLIST *p, int pos, elemtype *e);
int GetPosByElem(SEQLIST *p, elemtype v);
bool Getprio(SEQLIST *p, elemtype v, elemtype *e);
bool GetNext(SEQLIST *p, elemtype v, elemtype *e);
bool SetElem(SEQLIST *p, int pos, elemtype v);

bool InsertHead(SEQLIST *p, elemtype v);
bool InsertTail(SEQLIST *p, elemtype v);

bool DeleteHead(SEQLIST *p, elemtype *e);
bool DeleteTail(SEQLIST *p, elemtype *e);

bool Insert(SEQLIST *p,int pos,elemtype v);
bool Delete(SEQLIST *p, int pos, elemtype *e);

bool DispalyEx(SEQLIST *p, void(*pfunc)(void*));
bool Display(SEQLIST *p);

int Max(SEQLIST *p);
int Min(SEQLIST *p);

bool sort(SEQLIST *p);

bool unio(SEQLIST *p1, SEQLIST *p2);

bool MergeList(SEQLIST *p1, SEQLIST *p2, SEQLIST *p);

#endif