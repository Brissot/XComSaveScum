#include <string>
#include <iostream>
#include <filesystem>

int main()
{
  std::string path= "./";
  for (const auto & entry : std::filesystem::directory_iterator(path))
    std::cout << entry.path() << std::endl;
  return 0;
}
