#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ltsv.h"

LTSV ltsv_init(void)
{
	LTSV ltsv = (LTSV)malloc(sizeof(LTSV*));
	ltsv->keys = (const char**)malloc(sizeof(const char*[10]));
	ltsv->values = (const char**)malloc(sizeof(const char*[10]));
	for(int i = 0; i < 10; i++) {
		ltsv->keys[i] = NULL;
	}
	return ltsv;
}

void ltsv_delete(LTSV ltsv)
{
	free(ltsv);
}

void ltsv_dump(LTSV ltsv, char* dump, int maxlen)
{
	dump[0] = '\0';
	for(int i = 0; i < 10; i++) {
		if(ltsv->keys[i] == NULL)
		{
			continue;
		}
		strcat(dump, ltsv->keys[i]);
		strcat(dump, ":");
		strcat(dump, ltsv->values[i]);
		strcat(dump, "\n");
	}
}

void ltsv_set(LTSV ltsv, const char* key, const char* value)
{
	for(int i = 0; i < 10; i++) {
		if(ltsv->keys[i] == NULL)
		{
			ltsv->keys[i] = key;
			ltsv->values[i] = value;
			return;
		}
	}
}

const char* ltsv_get(LTSV ltsv, const char* key)
{
	for(int i = 0; i < 10; i++) {
		if(strcmp(ltsv->keys[i], key) == 0)
		{
			return ltsv->values[i];
		}
	}
	return NULL;
}
