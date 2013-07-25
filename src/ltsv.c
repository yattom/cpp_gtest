#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ltsv.h"

LTSV ltsv_init(void)
{
	LTSV ltsv = (LTSV)malloc(sizeof(LTSV*));
	ltsv->key = NULL;
	ltsv->value = NULL;
	return ltsv;
}

void ltsv_delete(LTSV ltsv)
{
	free(ltsv);
}

void ltsv_dump(LTSV ltsv, char* dump, int maxlen)
{
	if(ltsv->key == NULL) {
		strcpy(dump, "");
		return;
	}
	sprintf(dump, "%s:%s\n", ltsv->key, ltsv->value);
}

void ltsv_set(LTSV ltsv, const char* key, const char* value)
{
	ltsv->key = key;
	ltsv->value = value;
}

const char* ltsv_get(LTSV ltsv, const char* key)
{
	return ltsv->value;
}
