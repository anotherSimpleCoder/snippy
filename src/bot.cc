#include "bot.h"

Bot::Bot() {
	std::string token(std::getenv("BOT_TOKEN"));

	this->audioMaker = new AudioMaker();
	this->commandHandler = new CommandHandler(this->audioMaker);
	this->discordService = new DiscordService(token, this->commandHandler);
}

Bot::~Bot() {
	delete this->discordService;
}

void Bot::start() {
	//std::vector<std::string> lyrics = this->commandHandler->handle("turi ip ip ip ip ip");
	//this->audioMaker->makeTuriIp(&lyrics);
	this->discordService->connect();
}
