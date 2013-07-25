#ifndef _LTSV_H_
#define _LTSV_H_

struct _ltsv {
	int dummy;
};

typedef _ltsv* LTSV;

LTSV ltsv_init(void);
void ltsv_dump(LTSV, char* dump, int maxlen);

#endif  // _LTSV_H_

