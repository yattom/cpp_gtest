#include "ltsv.h"
#include "gtest/gtest.h"


class LtsvTests : public ::testing::Test {
public:
	char buf[1000];
	LTSV* ltsv;
	virtual void SetUp() {
		strcpy(buf, "uninitialized");
		ltsv = ltsv_init();
	}

	virtual void TearDown() {
		ltsv_delete(ltsv);
	}

	const char* dump(LTSV* ltsv)
	{
		ltsv_dump(ltsv, buf, sizeof(buf)/sizeof(buf[0]));
		return buf;
	}

};

TEST_F(LtsvTests, Empty) {
	EXPECT_STREQ("", dump(ltsv));
}

TEST_F(LtsvTests, SetAndGetOnlyOneKey) {
	ltsv_set(ltsv, "foo", "bar");
	EXPECT_STREQ("bar", ltsv_get(ltsv, "foo"));
	EXPECT_STREQ("foo:bar\n", dump(ltsv));
}

TEST_F(LtsvTests, SetAndGetTwoKeys) {
	ltsv_set(ltsv, "foo", "bar");
	ltsv_set(ltsv, "bazz", "quux");
	EXPECT_STREQ("bar", ltsv_get(ltsv, "foo"));
	EXPECT_STREQ("quux", ltsv_get(ltsv, "bazz"));
	EXPECT_STREQ("foo:bar\nbazz:quux\n", dump(ltsv));
}

