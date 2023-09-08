#ifndef SBIB_H
#define SBIB_H

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <dpp/dpp.h>

typedef uint64_t snowflake;
const snowflake SEKAICORD_ID = 636538718387306528;

// Initialization prototypes
void init_8ball(dpp::cluster & bot);
void init_textquest(dpp::cluster & bot);

// Handler prototypes
void handle_8ball(const dpp::interaction_create_t & event);
void handle_textquest(const dpp::interaction_create_t & event, const dpp::command_interaction & cmd_data, bool is_valid_command);

const std::string SBIBO_EMOJI = "<:sbibo:864916773186175036>";
const std::string SBIBO_EMOJI_L = "<:sbiboleft:864916822679486484>";
const std::string SBIBO_EMOJI_A = "<:sbiboangery:864916789258747946>";

static const size_t SIZE = 12;
static const std::string responses[SIZE] = 
    {
        SBIBO_EMOJI, 
        SBIBO_EMOJI_L,
        "A shizuku may appear if you do",
        "Yes, but you could sbib instead",
        "It would be better to sbib",
        "Signs point to sbib",
        "Outlook sbib",
        SBIBO_EMOJI + " 👍 !!!",
        "Only if you roll a sbib",
        "No, but have a sbib in these trying times " + SBIBO_EMOJI,
        "If you sbib, it will happen",
        SBIBO_EMOJI_A
    };

#endif