#include <gtest/gtest.h>
#include <libcsc/time/time.hpp>

using namespace operator_overload;
using namespace operator_overload::literals;

TEST(Time, Output) {
    std::stringstream out;
    out << operator_overload::Time(810549);
    out << operator_overload::TimeSpan(-810549);
    out << operator_overload::Time(0);
    out << operator_overload::Time(9);
    
    const std::string expected =
    "09d 09h 09m 09s "
    "-09d 09h 09m 09s "
    "00d 00h 00m 00s "
    "00d 00h 00m 09s ";
   
    EXPECT_EQ(expected, out.str());
}

TEST(Time, Literal) {
    auto t1 = 9_d + 9_h + 9_m + 9_s;
    operator_overload::TimeSpan t2(810549);
    EXPECT_EQ(t1.getCurrentTime(), t2.getCurrentTime());
}

TEST(Time, Operator) {
    operator_overload::Time t(-3_s);
    operator_overload::Time exp_t(-3);
    EXPECT_EQ(t.getCurrentTime(), exp_t.getCurrentTime());

    operator_overload::TimeSpan tS(10_s);
    operator_overload::TimeSpan exp_tS(10);
    EXPECT_EQ(tS.getCurrentTime(), exp_tS.getCurrentTime());

    t = 15_m;
    operator_overload::Time tt(30_m);
    tS = tt - t;
    exp_tS = 15_m;
    EXPECT_EQ(tS.getCurrentTime(), exp_tS.getCurrentTime());

    t = 6_m;
    operator_overload::TimeSpan ttS(2_m);
    t = t - ttS;
    exp_t = 4_m;
    EXPECT_EQ(t.getCurrentTime(), exp_t.getCurrentTime());

    tS = 6_d;
    ttS = 3_d;
    tS = tS + ttS;
    exp_tS = 9_d;
    EXPECT_EQ(tS.getCurrentTime(), exp_tS.getCurrentTime());

    tS = 9_h;
    ttS = 3_h;
    tS = tS - ttS;
    exp_tS = 6_h;
    EXPECT_EQ(tS.getCurrentTime(), exp_tS.getCurrentTime());
}
