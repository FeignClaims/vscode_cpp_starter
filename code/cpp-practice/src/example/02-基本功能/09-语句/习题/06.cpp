#include <fstream>
#include <string>

void strip(std::ifstream& infile, std::ofstream& outfile);

auto main() -> int {
  std::string filename{"P206-comment.cc"};
  std::ifstream infile{filename};
  std::ofstream outfile{"out"};
  strip(infile, outfile);
  return 0;
}

void strip(std::ifstream& infile, std::ofstream& outfile) {
  std::string temp{};
  while (infile.good()) {
    std::getline(infile, temp);
    std::size_t pos1{temp.find('/')};
    switch (temp[pos1 + 1]) {
      case '/':
        outfile << temp.substr(pos1 + 2) << '\n';
        break;
      case '*':
        size_t pos2 = temp.find("*/");
        outfile << temp.substr(pos1 + 2, pos2) << '\n';
        while (pos2 == std::string::npos) {
          std::getline(infile, temp);
          pos2 = temp.find("*/");
          outfile << temp.substr(0, pos2) << '\n';
        }
    }
  }
}