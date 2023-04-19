#include "functii.h"
#include <string.h>

float string_to_float(char* str) {
	float nr = 0;
	int ok = 1, p=10, negativ=0;
	int i = 0;
	if (str[0] == '-')
		i++, negativ=1;
	while (i < strlen(str)) {
		if (str[i] >= '0' && str[i] <= '9' && ok)
			nr = nr * 10 + str[i] - '0';
		else if (str[i] >= '0' && str[i] <= '9' && !ok)
			nr = nr + (float)(str[i] - '0') / p, p *= 10;
		else if (str[i] == '.')
			ok = 0;
		else
			return -1;
		i++;
	}
	if (negativ)
		return -1*nr;
	return nr;
}