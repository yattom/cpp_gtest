#include "ltsv.h"
#include "gtest/gtest.h"

TEST(LtsvTest, Empty) {
	LTSV ltsv = ltsv_init();
	char buf[100] = "uninitialized";
	ltsv_dump(ltsv, buf, sizeof(buf)/sizeof(buf[0]));
	EXPECT_STREQ("", buf);
}

