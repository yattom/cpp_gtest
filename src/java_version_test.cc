#include "java_version.h"
#include "gtest/gtest.h"

TEST(JavaVersionTest, Validity) {
	EXPECT_TRUE(Version::isValid("JDK7u40"));
	EXPECT_FALSE(Version::isValid("hoge"));
	EXPECT_FALSE(Version::isValid("JDK7u9x"));
}
