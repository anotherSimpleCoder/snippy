#include <stdexcept>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <fmt/core.h>

#include <sndfile.h>

class AudioMaker {
private:
  std::unordered_map<std::string, std::pair<float*, int>> audios;

  std::pair<float*, int> openFile(std::string path);
  void writeFile(std::vector<float> audioData, std::string filename);
  std::pair<float*, int> turi();
  std::pair<float*, int> ip();
  std::vector<float> cleanUp(std::vector<float> audioData);

public:
  AudioMaker();
  ~AudioMaker();

  void makeTuriIp(std::vector<std::string>* lyrics, std::string filename);
};
