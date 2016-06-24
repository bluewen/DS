#ifndef _TRIP_H_
#define _TRIP_H_

typedef int elem_type;

typedef struct _TRIP
{
	elem_type e1;
	elem_type e2;
	elem_type e3;
}TRIP;



TRIP *InitTripEx(elem_type *v1, elem_type *v2, elem_type *v3);
bool DestoryTripEx(TRIP *p);

bool ClearTrip(TRIP *p);

bool Get(TRIP *p, int pos, elem_type *e);
bool Put(TRIP *p, int pos, elem_type v);

bool IsAscending(TRIP *p);
bool IsDescending(TRIP *p);

bool Max(TRIP *p, elem_type *e);
bool Min(TRIP *p, elem_type *e);


TRIP *Add1(TRIP *p1, TRIP *p2);
bool Add2(TRIP *p1, TRIP *p2);

void Show(TRIP *p);

#endif


















