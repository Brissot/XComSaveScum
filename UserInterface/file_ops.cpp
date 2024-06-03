#include <string>
#include <iostream>
#include <filesystem>

/* class to manage the day to day operations */
class SaveScummer {
public:
  /* the basepath of the game directory */
  std::filesystem::path basepath;
  
  SaveScummer(std::filesystem::path basepath)
  {
    this->basepath= basepath;
  }

  void list_files(std::filesystem::path path)
  {
    try
    {
      for (const auto& entry : std::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;
    }
    catch (std:: filesystem::filesystem_error& e)
    {
      std::cout << "Could Not List " << path << std::endl
                << "error: " << std::endl << e.what() << std::endl;
    }
  }

  void copy_save(std::filesystem::path from, std::filesystem::path to)
  {
    try
    {
      std::filesystem::copy_file(from, to);
    }
    catch (std::filesystem::filesystem_error& e)
    {
      std::cout << "Could Not Copy " << from << " to " << to << std::endl
                << "error:" << std::endl << e.what() << std::endl;
    }
  }
};


int main()
{
  std::filesystem::path path= "./";
  SaveScummer* driver= new SaveScummer(path);
  
  driver->list_files(path);

  std::filesystem::path from_path= "./test1";
  std::filesystem::path to_path= "./test2";

  driver->copy_save(from_path, to_path);

  delete driver;
  
  return 0;
}
