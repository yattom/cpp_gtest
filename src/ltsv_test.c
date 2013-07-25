#include "ltsv.h"
#include "gtest/gtest.h"

static char buf[1000] = "uninitialized";

const char* dump(LTSV ltsv)
{
	ltsv_dump(ltsv, buf, sizeof(buf)/sizeof(buf[0]));
	return buf;
}

TEST(LtsvTest, Empty) {
	LTSV ltsv = ltsv_init();
	EXPECT_STREQ("", dump(ltsv));
}

TEST(LtsvTest, SetAndGet) {
	LTSV ltsv = ltsv_init();
	ltsv_set(ltsv, "foo", "bar");
	EXPECT_STREQ("bar", ltsv_get(ltsv, "foo"));
	EXPECT_STREQ("foo:bar\n", dump(ltsv));
}

