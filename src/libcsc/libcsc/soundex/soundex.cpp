#include <libcsc/soundex/soundex.hpp>
#include <libcsc/soundex/soundexUtility.hpp>

bool isVowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
      ch == 'y')
    return true;
  return false;
}
char replaceChar(char ch) {
  if (ch == 'b' || ch == 'f' || ch == 'p' || ch == 'v') {
    return '1';
  }
  if (ch == 'c' || ch == 'g' || ch == 'j' || ch == 'k' || ch == 'q' ||
      ch == 'q' || ch == 's' || ch == 'x' || ch == 'z') {
    return '2';
  }
  if (ch == 'd' || ch == 't') {
    return '3';
  }
  if (ch == 'l') {
    return '4';
  }
  if (ch == 'm' || ch == 'n') {
    return '5';
  }
  if (ch == 'r') {
    return '6';
  }
  return ch;
}
std::string soundex_hash(std::string_view str) {
  if (str.length() == 0)
    return "0000"; // TODO exception

  std::string userString(str);
  std::transform(userString.begin(), userString.end(), userString.begin(),
                 tolower);
  char firstChar = toupper(userString[0]);

  userString.erase(std::remove(userString.begin() + 1, userString.end(), 'h'),
                   userString.end());
  userString.erase(std::remove(userString.begin() + 1, userString.end(), 'w'),
                   userString.end());

  std::transform(userString.begin(), userString.end(), userString.begin(),
                 replaceChar);
  // std::for_each(userString.begin() + 1, userString.end(), replaceChar);

  userString.erase(std::unique(userString.begin(), userString.end()),
                   userString.end());
  userString.erase(
      std::remove_if(userString.begin() + 1, userString.end(), isVowel),
      userString.end());
  userString[0] = firstChar;
  while (userString.length() < 4) {
    userString += '0';
  }
  return userString.substr(0, 4);
}