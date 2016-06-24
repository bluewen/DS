#include "TRIP.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



TRIP *InitTripEx(elem_type *v1, elem_type *v2, elem_type *v3)
{
	TRIP *p = (TRIP *)malloc(sizeof(TRIP)* 1);
	assert(p != NULL);

	p->e1 = *v1;
	p->e2 = *v2;
	p->e3 = *v3;

	return p;
}

bool DestoryTripEx(TRIP *p)
{
	if (p == NULL)
	{
		return false;
	}

	delete p;

	return true;

}



bool ClearTrip(TRIP *p)
{
	if (p == NULL)
	{
		return false;
	}

	p->e1 = 0;
	p->e2 = 0;
	p->e3 = 0;

	return true;
}


bool Get(TRIP *p, int pos, elem_type *e)
{
	if (p == NULL || pos < 1 || pos > 3)
	{
		return false;
	}

	if (pos == 1)
	{
		*e = p->e1;
	}
	else if (pos == 2)
	{
		*e = p->e2;
	}
	else
	{
		*e = p->e3;
	}


	return true;
}

bool Put(TRIP *p, int pos, elem_type v)
{
	if (p == NULL || pos < 1 || pos > 3)
	{
		return false;
	}

	if (pos == 1)
	{
		p->e1 = v;
	}
	else if (pos == 2)
	{
		p->e2 = v;
	}
	else
	{
		p->e3 = v;
	}


	return true;


}

//10 30 20
bool IsAscending(TRIP *p)
{
	/*
	if (p == NULL)
	{
	return false;
	}
	*/

	assert(p != NULL);

	if (p->e1 < p->e2)
	{
		if (p->e2 < p->e3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}


///10 30 20
bool IsDescending(TRIP *p)
{
	assert(p != NULL);

	if (p->e1 > p->e2)
	{
		if (p->e2 > p->e3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}



}

bool Max(TRIP *p, elem_type *e)
{
	if (p == NULL)
	{
		return false;
	}

	elem_type tmp;

	if (p->e1 < p->e2)
	{
		tmp = p->e1;
		p->e1 = p->e2;
		p->e2 = tmp;
	}
	if (p->e1 < p->e3)
	{
		tmp = p->e1;
		p->e1 = p->e3;
		p->e3 = tmp;

	}
	if (p->e2 < p->e3)
	{
		tmp = p->e2;
		p->e2 = p->e3;
		p->e3 = tmp;
	}

	*e = p->e1;

	return true;


}

bool Min(TRIP *p, elem_type *e)
{
	if (p == NULL)
	{
		return false;
	}

	elem_type tmp;

	if (p->e1 < p->e2)
	{
		tmp = p->e1;
		p->e1 = p->e2;
		p->e2 = tmp;
	}
	if (p->e1 < p->e3)
	{
		tmp = p->e1;
		p->e1 = p->e3;
		p->e3 = tmp;

	}
	if (p->e2 < p->e3)
	{
		tmp = p->e2;
		p->e2 = p->e3;
		p->e3 = tmp;
	}

	*e = p->e3;

	return true;
}

TRIP *Add1(TRIP *p1, TRIP *p2)
{


	TRIP *p = (TRIP *)malloc(sizeof(TRIP)* 1);
	assert(p != NULL);

	p->e1 = p1->e1 + p2->e1;
	p->e2 = p1->e2 + p2->e2;
	p->e3 = p1->e3 + p1->e3;

	return p;

}

bool Add2(TRIP *p1, TRIP *p2)
{
	if (p1 == NULL)
	{
		return false;
	}
	if (p2 == NULL)
	{
		return false;
	}

	p1->e1 += p2->e1;
	p1->e2 += p2->e2;
	p1->e3 += p2->e3;

	return true;
}

void Show(TRIP *p)
{
	assert(p != NULL);

	printf("%d %d %d\n", p->e1, p->e2, p->e3);


}