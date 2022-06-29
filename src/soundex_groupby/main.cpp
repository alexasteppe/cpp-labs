#include <libcsc/soundex/soundexUtility.hpp>

#include <cxxopts.hpp>

#include <string>

int main(int argc, char **argv) {
  cxxopts::Options options("path");

  try {
    options.add_options()("input", "CSV file", cxxopts::value<std::string>());

    const auto result = options.parse(argc, argv);

    if (result.count("input") != 1) {
      std::cout << options.help() << "\n";
      return 0;
    }

    const auto value = result["input"].as<std::string>();

    printJson(value);
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  // printJson();
}
