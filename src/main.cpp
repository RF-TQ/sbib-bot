#include "sbib.h"

int main()
{

  const char* TOKEN = getenv("DISCORD_TOKEN");

	if (TOKEN == nullptr) {
		std::cerr << "Could not find the DISCORD_TOKEN environment variable.\n";
		exit(1);
	}

    dpp::cluster bot(TOKEN);
    
    // Writes back to the console when the bot successfully connects
    bot.on_ready([&bot](const auto & event) {
        
        std::cout << "Logged in as " << bot.me.username << "\n";
            
        // See sbib.cpp::handle_8ball() for context
        srand(time(NULL)); 

        // Init for slash commands
        init_8ball(bot);
        // init_textquest(bot);
            
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
        // if (cmd_data.name == "sbib-quest") {
        //    handle_textquest(event, cmd_data, true);    
        //    }
        }
    });    
  
    // When a message is sent, listens for a certain string,
    // and replies in the same channel as the message if that string matches.
    // NOTE: Uses the Message Content intent, although that won't be relevant since this only runs on two guilds
    bot.on_message_create([&bot](const auto & event) {
        // Does this need the identify scope to ping back the user who initiated the event? (it does, figure out how to get identify auth)
        if (event.msg.content == "?ping sbib") {   
            std::string reply = event.msg.author.get_mention() + " <:sbiboping:911528061407744000>";
            bot.message_create(dpp::message(event.msg.channel_id, reply));
        }
        else if (event.msg.content == "hi sbib") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibosmile:1091748454407082104>"));
        }
        else if (event.msg.content == "sbib?") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibo:864916773186175036> !"));
        }
        else if (event.msg.content == "sbib do a flip") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibo:864916773186175036>"));
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbiboleft:864916822679486484>"));
        }
        else if (event.msg.content == "bye sbib") {
            bot.message_create(dpp::message(event.msg.channel_id, "<:sbibodontfeelsogood:1091749451791609916> 👍"));
        }
    });

    // "The parameter which we set to false indicates if the function should return once all shards are created. Passing false here tells the program you do not need to do anything once bot.start is called, so the return statement directly afterwards is never reached."
    bot.start(false);
    return 0;
}
