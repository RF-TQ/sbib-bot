#include "sbib.h"

int main()
{
    setenv("DISCORD_TOKEN", /* token omitted */, 1);

	if (!getenv("DISCORD_TOKEN")) {
		std::cout << "Could not find the DISCORD_TOKEN environment variable.\n";
		return 1;
	}

    dpp::cluster bot(getenv("DISCORD_TOKEN"));
    
  // Writes back to the console when the bot successfully connects
  bot.on_ready([&bot](const auto & event) {
    std::cout << "Logged in as " << bot.me.username << "\n";
        
    srand(time(NULL)); 

    // Init for slash commands
    init_8ball(bot);
    init_textquest();
            
    });

    // Interaction handler for slash commands
  bot.on_interaction_create([&bot](const dpp::interaction_create_t &event) {
    if (event.command.type == dpp::it_application_command) {
      dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            
      // eightball: produces a random response from a predefined string array
      if (cmd_data.name == "sbib-ball") {
        handle_8ball(event);
        }

      // textquest: logs commands to console and keeps a running counter of commands by type
      if (cmd_data.name == "sbib-quest") {
        handle_textquest(event, cmd_data, true);    
        }
      }
    });    
  
    // When a message is sent, listens for a certain string,
    // and replies in the same channel as the message if that string matches.
    // NOTE: Uses the Message Content intent, although that won't be relevant since this only runs on two guilds
    bot.on_message_create([&bot](const auto & event) {
        // Does this need the identify scope to ping back the user who initiated the event?
        if (event.msg.content == "?ping sbib") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbiboping:911528061407744000>"));
        }
        else if (event.msg.content == "hi sbib") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibosmile:864916840752349204>"));
        }
        else if (event.msg.content == "sbib?") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibo:864916773186175036> !"));
        }
    });

    bot.start(false);
    return 0;
}
