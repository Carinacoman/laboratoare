#include <stdio.h>
#include "NumberList.h"

int main()
{
	NumberList x;
	x.Init();

	x.Add(10);
	x.Add(7);
	x.Add(37);
	x.Add(19);
	x.Add(1);

	x.Print();

	x.Sort();

	x.Print();


	return 0;
}