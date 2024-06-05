#include "discordService.h"

DiscordService::DiscordService(std::string token, CommandHandler* commandHandler) {
	this->commandHandler = commandHandler;
	
	this->discord = new dpp::cluster(token);
	this->discord->on_log(dpp::utility::cout_logger());

	this->discord->on_ready([this](const dpp::ready_t& event) {
		if(dpp::run_once<struct register_bot_commands>()) {
			dpp::slashcommand makeCommand("make", "Creates audio", this->discord->me.id);
			makeCommand.add_option(dpp::command_option(dpp::command_option_type::co_string, "lyrics", "The lyrics of your snippet", true));

			this->discord->global_command_create(makeCommand);
		}
	});

	this->discord->on_slashcommand([this](const dpp::slashcommand_t& event){
		try {
			this->commandHandler->handle(event);
		} catch(const std::runtime_error& e) {
			dpp::message reply(event.command.channel_id, e.what());
			event.reply(reply);
		}
		
	});
}

DiscordService::~DiscordService() {
	delete this->discord;
}

void DiscordService::connect() {
		this->discord->start(dpp::st_wait);
}

