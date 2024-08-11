#include <stdio.h>
#include "include/choose_operation/choose_operation.h"

int main(int argc, char * argv[])
{
	printf("%d\n", get_operation(argv[1]));

	return 0;
}