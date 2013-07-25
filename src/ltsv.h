#ifndef _LTSV_H_
#define _LTSV_H_

struct _ltsv {
	int max_entries_count;
	struct _entry {
		const char* key;
		const char* value;
	} *entries;
};

typedef _ltsv LTSV;

LTSV* ltsv_init(void);
void ltsv_delete(LTSV*);
void ltsv_dump(LTSV*, char* dump, int maxlen);
int ltsv_dump_required_len(LTSV*);
void ltsv_set(LTSV*, const char* key, const char* value);
const char* ltsv_get(LTSV*, const char* key);

#endif  // _LTSV_H_

