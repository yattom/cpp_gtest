#ifndef _LTSV_H_
#define _LTSV_H_

struct _ltsv {
	const char* key;
	const char* value;
};

typedef _ltsv* LTSV;

LTSV ltsv_init(void);
void ltsv_dump(LTSV, char* dump, int maxlen);
void ltsv_set(LTSV, const char* key, const char* value);
const char* ltsv_get(LTSV, const char* key);

#endif  // _LTSV_H_

