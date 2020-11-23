#include "gtest/gtest.h"
#include <string>
#include <cmath>
#include <vector>
#include "configparser.hpp"

using namespace std;

TEST(Configparser, aConfig) {

  string path = "reference/testconfig";
  ConfigParser parser = ConfigParser(path);

  string c11 = parser.aConfig<string>("Section1", "example1");
  int c12 = parser.aConfig<int>("Section1", "example2");
  bool c13 = parser.aConfig<bool>("Section1", "example3");
  string c16 = parser.aConfig<string>("Section1", "example6");

  ASSERT_TRUE(c11.compare("string") == 0);
  ASSERT_TRUE(c12 == 4);
  ASSERT_TRUE(c13);
  ASSERT_TRUE(c16.compare("\"test!?$§\"") == 0);
}

TEST(Configparser, aConfigVec) {

  string path = "reference/testconfig";
  ConfigParser parser = ConfigParser(path);

  vector<string> c14 = parser.aConfigVec<string>("Section1", "example4");
  vector<bool> c15 = parser.aConfigVec<bool>("Section1", "example5");
  vector<long long> c21 = parser.aConfigVec<long long>("Section2", "example1");
  vector<double> c22 = parser.aConfigVec<double>("Section2", "example2");

  vector<string> compare14{"string1", "string2", "string3"};
  vector<bool> compare15{true, false, true};
  vector<long long> compare21{1, 2, 3, 4};

  ASSERT_TRUE(std::equal(c14.begin(), c14.end(), compare14.begin()));
  ASSERT_TRUE(std::equal(c15.begin(), c15.end(), compare15.begin()));
  ASSERT_TRUE(std::equal(c21.begin(), c21.end(), compare21.begin()));
  ASSERT_TRUE(abs(c22[0] - 5.1) < 10e-12);
  ASSERT_TRUE(abs(c22[1] - 6.3) < 10e-12);
  ASSERT_TRUE(abs(c22[2] - 7.5) < 10e-12);
}
