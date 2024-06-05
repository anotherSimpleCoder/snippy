#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fmt/core.h>
#include <cstdio>

#include <dpp/dpp.h>

#include "audioMaker.h"
#include "utils.h"

class CommandHandler{
private:
  AudioMaker* audioMaker;

  std::string handleTuriIp(std::string commandString);
public:
  CommandHandler(AudioMaker* audioMaker);
  void handle(const dpp::slashcommand_t& event);
};
