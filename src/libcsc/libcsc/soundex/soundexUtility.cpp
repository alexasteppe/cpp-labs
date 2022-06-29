#include <libcsc/soundex/soundexUtility.hpp>

#include <libcsc/soundex/soundex.hpp>

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

void printJson(std::string inputFilePath) {
  std::ifstream data;
  data.open(inputFilePath);

  std::vector<std::string> name;
  std::map<std::string, std::vector<std::string>> res;
  std::string line;

  while (getline(data, line, ',')) {
    name.push_back(line);
    getline(data, line);
  }

  for (auto &i : name) {
    res[soundex_hash(i)].push_back(i);
  }

  //  for (auto &test : res) {
  //    std::cout << test.first << "\n";
  //  }

  std::ofstream jsonOutput("outputData.json");
  nlohmann::json j_map(res);
  jsonOutput << std::setw(4) << j_map << std::endl;

  jsonOutput.close();
}
