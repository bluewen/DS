#include "TRIP.h"


int main()
{
	//i1,i2,i3;
	elem_type i1 = 10;
	elem_type i2 = 20;
	elem_type i3 = 30;

	TRIP *t1 = InitTripEx(&i1, &i2, &i3);
	TRIP *t2 = InitTripEx(&i1, &i2, &i3);

	//ClearTrip(t1);
	//Put(t1, 1, 44);

	TRIP *t3 = Add1(t1, t2);
	Show(t3);

	DestoryTripEx(t1);
	DestoryTripEx(t2);


	return 0;
}