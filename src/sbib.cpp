#include "sbib.h"

// init_8ball()
// Initializes the "sbib-ball" slash command
void init_8ball(dpp::cluster & bot)
{
    dpp::slashcommand eightball;        
        eightball.set_name("sbib-ball")
          .set_description("Ask the magic sbib-ball a question.")
          .set_application_id(bot.me.id)
          .add_option(
              dpp::command_option(dpp::co_string, "question", "Ask a question", true) 
          );

    bot.global_command_create(eightball);
    std::cout << "sbib-ball successfully initialized\n";
  
    return;
}

// init_textquest()
// Initializes the "sbib-quest" slash command set 
void init_textquest(dpp::cluster & bot)
{   
    dpp::slashcommand textquest;
        textquest.set_name("sbib-quest")
          .set_description("Actions related to the text adventure game.")
          .set_application_id(bot.me.id)
          .add_option(
              dpp::command_option(dpp::co_sub_command, "command", "Log a command to the text adventure console.")
                  .add_option(dpp::command_option(dpp::co_string, "interact", "Interact with a specific object in the area", false))
                  .add_option(dpp::command_option(dpp::co_string, "use-item", "Use an item from the inventory on another object, inventory item, or party member", false))
                  .add_option(dpp::command_option(dpp::co_string, "exit", "Navigate to the next area through an available exit", false))
                  .add_option(dpp::command_option(dpp::co_string, "wildcard", "For creative actions suggested by the situation", false))                  
            )
          .add_option(
              dpp::command_option(dpp::co_sub_command, "turn", "Outputs current turn data.")      
            );        

    bot.guild_command_create(textquest, SEKAICORD_ID);
    std::cout << "sbib-quest successfully initialized\n";

    return;
}

// handle_8ball
// Handler for sbib-ball slash command
void handle_8ball(const dpp::interaction_create_t & event)
{
    // Do something with this later on
    // Doesn't this return the value of the query, as in 
    // question: "Will I lucksack on the next fes?"
    // std::string query = std::get<std::string>(event.get_parameter("question"));
                    
    // I probably misread the docs on this considering it only ever outputs responses[0]   
    // std::default_random_engine generator;
    // std::uniform_int_distribution<int> distr(0, SIZE - 1);

    std::string response = responses[rand() % 12];

    event.reply(dpp::ir_channel_message_with_source, response);

    return;
}

// handle_textquest()
// Handler for sbib-quest slash command
void handle_textquest(const dpp::interaction_create_t & event, const dpp::command_interaction & cmd_data, bool is_valid_command)
{
    if (cmd_data.options[0].name == "command") {

        // Validation check: Must use one of the four options
        if (cmd_data.options[0].options.size() <= 0) {
            is_valid_command = false;
        }

        if (is_valid_command == false){
            event.reply(dpp::ir_channel_message_with_source, "Command invalid! Try again.");
            return;
        }        
        else {
            std::string turn_action = std::get<std::string>(cmd_data.options[0].options[0].value);

            std::cout << "Command received: " 
                    << turn_action << '\n';

            event.reply(dpp::ir_channel_message_with_source, "Command logged!");

            // This is going to require some sort of class to keep count of each interaction type
            // For now, logging the action type to the console will do
            if (cmd_data.options[0].options[0].name == "interact") {
                std::cout << "Command type: interaction\n";
            }
            else if (cmd_data.options[0].options[0].name == "use-item") {
                std::cout << "Command type: item usage\n";
            }
            else if (cmd_data.options[0].options[0].name == "exit") {
                std::cout << "Command type: area movement\n";
            }
            else if (cmd_data.options[0].options[0].name == "wildcard") {
                std::cout << "Command type: special\n";
            }
        }

    }
    else if (cmd_data.options[0].name == "turn") {
        // Probably needs a class as well
        event.reply(dpp::ir_channel_message_with_source, "Current turn data unavailable.");
    } 

    return;

}