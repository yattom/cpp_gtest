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

TEST_F(LtsvTests, DumpKnowsRequiredLength) {
	EXPECT_EQ(1, ltsv_dump_required_len(ltsv));
	ltsv_set(ltsv, "k", "v");
	EXPECT_EQ(5, ltsv_dump_required_len(ltsv));
}

TEST_F(LtsvTests, DumpDoesntBufferOverrun_NotEnough) {
	ltsv_set(ltsv, "k", "v");
	ltsv_dump(ltsv, buf, 4); // "k:v\n" requires length of 5
	EXPECT_STREQ("uninitialized", buf);
}

TEST_F(LtsvTests, DumpDoesntBufferOverrun_JustEnough) {
	ltsv_set(ltsv, "k", "v");
	ltsv_dump(ltsv, buf, 5); // "k:v\n" requires length of 5
	EXPECT_STREQ("k:v\n", buf);
}

TEST_F(LtsvTests, DumpDoesntBufferOverrun_MoreThanEnough) {
	ltsv_set(ltsv, "k", "v");
	ltsv_dump(ltsv, buf, 6); // "k:v\n" requires length of 5
	EXPECT_STREQ("k:v\n", buf);
}
