#include <dpp/dpp.h>
#include <string>
#include <functional>
#include <stdexcept>

#include "commandHandler.h"

class DiscordService {
private:
	dpp::cluster* discord;
	CommandHandler* commandHandler;

public:
	DiscordService(std::string token, CommandHandler* commandHandler);
	~DiscordService();

	void connect();
};
