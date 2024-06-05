#include "commandHandler.h"

CommandHandler::CommandHandler(AudioMaker* audioMaker) {
  this->audioMaker = audioMaker;
}

void CommandHandler::handle(const dpp::slashcommand_t& event) {
  std::string name = event.command.get_command_name();
	std::string lyrics = std::get<std::string>(event.get_parameter("lyrics"));
  std::regex turiIpPattern("turi|ip");
  dpp::message reply(event.command.channel_id, lyrics);

  if(std::regex_search(lyrics, turiIpPattern)) {
    std::string filename = this->handleTuriIp(lyrics);
    reply.add_file(filename, dpp::utility::read_file(filename));
    event.reply(reply); 
    remove(filename.c_str());

  } else {
      throw std::runtime_error("Invalid command!");
  }
}

std::string CommandHandler::handleTuriIp(std::string commandString) {
  std::string filename = fmt::format("{}.wav", snippyUtils::generateUuid());
  std::regex turiIpPattern("turi|ip");
  std::vector<std::string> lyrics;


  for(std::sregex_iterator i(commandString.begin(), commandString.end(), turiIpPattern), end; i != end; ++i) {
    lyrics.push_back(i->str());
  }

  this->audioMaker->makeTuriIp(&lyrics, filename);

  return filename;
}
