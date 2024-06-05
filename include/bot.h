#include <string>
#include <cstdlib>
#include "discordService.h"

class Bot {
private:
	DiscordService* discordService;
	CommandHandler* commandHandler;
	AudioMaker* audioMaker;

public:
	Bot();
	~Bot();

	void start();
};
