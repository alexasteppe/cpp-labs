#include <gtest/gtest.h>

#include <libcsc/soundex/soundex.hpp>

#include <string>

TEST(Soundex, Hash) {
  std::string vowelName = soundex_hash("Aiya");
  EXPECT_EQ(vowelName, "A000");

  std::string hwName = soundex_hash("Hwhwhw");
  EXPECT_EQ(hwName, "H000");

  std::string oneLetterName = soundex_hash("J");
  EXPECT_EQ(oneLetterName, "J000");

  std::string upperCaseName = soundex_hash("NORA");
  EXPECT_EQ(upperCaseName, "N600");

  std::string lowerCaseName = soundex_hash("nora");
  EXPECT_EQ(lowerCaseName, "N600");

  EXPECT_EQ(upperCaseName, lowerCaseName);

  std::string alikeLetterName = soundex_hash("Sxzkq");
  EXPECT_EQ(alikeLetterName, "S000");

  std::string casualName = soundex_hash("Everly");
  EXPECT_EQ(casualName, "E164");
}
