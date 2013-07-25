#include <stdlib.h>
#include <string.h>
#include "ltsv.h"

LTSV ltsv_init(void)
{
	return NULL;
}

void ltsv_dump(LTSV, char* dump, int maxlen)
{
	strcpy(dump, "");
}

void ltsv_set(LTSV, const char* key, const char* value)
{
}

const char* ltsv_get(LTSV, const char* key)
{
	return "bar";
}
