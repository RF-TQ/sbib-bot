#ifndef SBIB_H
#define SBIB_H

#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>

const uint64_t SEKAICORD_ID = 636538718387306528; 

// Initialization prototypes
void init_8ball(dpp::cluster & bot);
void init_textquest(dpp::cluster & bot);

// Handler prototypes
void handle_8ball(const dpp::interaction_create_t & event);
void handle_textquest(const dpp::interaction_create_t & event, const dpp::command_interaction & cmd_data, bool is_valid_command);

static const size_t SIZE = 12;
static const std::string responses[SIZE] = 
    {
        "<:sbibo:864916773186175036>", 
        "<:sbiboleft:864916822679486484>",
        "A shizuku may appear if you do",
        "Yes, but you could sbib instead",
        "It would be better to sbib",
        "Signs point to sbib",
        "Outlook sbib",
        "<:sbibo:864916773186175036> 👍 !!!",
        "Only if you roll a sbib",
        "No, but have a sbib in these trying times <:sbibo:864916773186175036>",
        "If you sbib, it will happen",
        "<:sbiboangery:864916789258747946>"
    };

#endif