#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ltsv.h"

const int MAX_ENTRIES_COUNT = 10;

void init_entry(struct _ltsv::_entry* entry) {
	entry->key = NULL;
	entry->value = NULL;
}

LTSV ltsv_init(void)
{
	LTSV ltsv = (LTSV)malloc(sizeof(LTSV*));
	ltsv->max_entries_count = MAX_ENTRIES_COUNT;
	ltsv->entries = (struct _ltsv::_entry*)malloc(sizeof(struct _ltsv::_entry[ltsv->max_entries_count]));
	for(int i = 0; i < ltsv->max_entries_count; i++) {
		init_entry(ltsv->entries + i);
	}
	return ltsv;
}

void ltsv_delete(LTSV ltsv)
{
	free(ltsv->entries);
	free(ltsv);
}

void ltsv_dump(LTSV ltsv, char* dump, int maxlen)
{
	dump[0] = '\0';
	for(int i = 0; i < ltsv->max_entries_count; i++) {
		if(ltsv->entries[i].key == NULL)
		{
			continue;
		}
		strcat(dump, ltsv->entries[i].key);
		strcat(dump, ":");
		strcat(dump, ltsv->entries[i].value);
		strcat(dump, "\n");
	}
}

void ltsv_set(LTSV ltsv, const char* key, const char* value)
{
	for(int i = 0; i < ltsv->max_entries_count; i++) {
		if(ltsv->entries[i].key == NULL)
		{
			ltsv->entries[i].key = key;
			ltsv->entries[i].value = value;
			return;
		}
	}
}

const char* ltsv_get(LTSV ltsv, const char* key)
{
	for(int i = 0; i < ltsv->max_entries_count; i++) {
		if(strcmp(ltsv->entries[i].key, key) == 0)
		{
			return ltsv->entries[i].value;
		}
	}
	return NULL;
}
