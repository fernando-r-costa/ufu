#include <stdio.h>
#include <math.h>

int main()
{
	int num;

	scanf("%d", &num);

	for(int i = 0; i < num; i++) {
		if(num % (i+1) == 0) {
			printf("%d ", i+1);
		}
	}

	return 0;
}