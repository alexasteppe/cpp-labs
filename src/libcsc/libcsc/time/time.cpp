#include <libcsc/time/time.hpp>
namespace operator_overload {

    std::ostream &operator<<(std::ostream &out, const GenTime &time) {

      int temp = abs(time.getCurrentTime());
      int myDay = temp / secInDay;
      temp %= secInDay;
      int myHour = temp / secInHour;
      temp %= secInHour;
      int myMin = temp / secInMin;
      int mySec = temp % secInMin;

      if (time.getCurrentTime() < 0) {
        out << "-";
      }
      out << std::setfill('0') << std::setw(2) << myDay << "d " << std::setfill('0')
          << std::setw(2) << myHour << "h " << std::setfill('0') << std::setw(2)
          << myMin << "m " << std::setfill('0') << std::setw(2) << mySec << "s ";

      return out;
}

    TimeSpan::TimeSpan(int newTimeSpan) : timeSpan(newTimeSpan) {}

    int TimeSpan::getCurrentTime() const { return timeSpan; }

    TimeSpan TimeSpan::operator+(const TimeSpan &otherTimeSpan) const {
      return TimeSpan(timeSpan + otherTimeSpan.getCurrentTime());
    }

    TimeSpan TimeSpan::operator-(const TimeSpan &otherTimeSpan) const {
      return TimeSpan(timeSpan - otherTimeSpan.getCurrentTime());
    }

    TimeSpan TimeSpan::operator-() const { return TimeSpan(-timeSpan); }

    Time::Time(int newTime) : time(newTime) {}

    int Time::getCurrentTime() const { return time; }

    TimeSpan Time::operator-(const Time &otherTime) const {
      return static_cast<TimeSpan>(time - otherTime.getCurrentTime());
    }

    Time Time::operator+(const TimeSpan &timeSpan) const {
      return Time(time + timeSpan.getCurrentTime());
    }

    Time Time::operator-(const TimeSpan &timeSpan) const {
      return Time(time - timeSpan.getCurrentTime());
    }

    Time Time::operator-() const { return Time(-time); }

    namespace literals {
        TimeSpan operator ""_d(unsigned long long time) {
          return TimeSpan(static_cast<int>(time) * 60 * 60 * 24);
        }

        TimeSpan operator ""_h(unsigned long long time) {
          return TimeSpan(static_cast<int>(time) * 60 * 60);
        }

        TimeSpan operator ""_m(unsigned long long time) {
          return TimeSpan(static_cast<int>(time) * 60);
        }

        TimeSpan operator ""_s(unsigned long long time) {
          return TimeSpan(static_cast<int>(time));
        }
    }  // namespace literals
}  // namespace operator_overload

