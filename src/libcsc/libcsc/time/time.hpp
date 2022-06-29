#pragma once

#include <iostream>
#include <iomanip>
#include <string>

namespace operator_overload {
constexpr int secInMin = 60;
constexpr int secInHour = secInMin * 60;
constexpr int secInDay = secInHour * 24;

class GenTime {
public:
  virtual int getCurrentTime() const = 0;
  friend std::ostream &operator<<(std::ostream &out, const GenTime &time);
};

class Time;

class TimeSpan : public GenTime {

  int timeSpan;

public:
  explicit TimeSpan(int newTimeSpan);

  int getCurrentTime() const override;

  TimeSpan operator+(const TimeSpan &otherTimeSpan) const;

  TimeSpan operator-(const TimeSpan &otherTimeSpan) const;

  TimeSpan operator-() const;
};

class Time : public GenTime {
  int time;

public:
  explicit Time(int newTime);

  Time(const TimeSpan& castTimeSpan) { time = castTimeSpan.getCurrentTime(); }

  int getCurrentTime() const override;

  TimeSpan operator-(const Time &otherTime) const;

  Time operator+(Time) = delete;

  Time operator+(const TimeSpan &timeSpan) const;

  Time operator-(const TimeSpan &timeSpan) const;

  Time operator-() const;
};

  namespace literals {
  TimeSpan operator""_d(unsigned long long time);

  TimeSpan operator""_h(unsigned long long time);

  TimeSpan operator""_m(unsigned long long time);

  TimeSpan operator""_s(unsigned long long time);
  }
}
