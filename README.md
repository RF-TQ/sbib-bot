# sbib-bot
A Discord bot designed to manage a text adventure game. It also has a silly 8-ball function packaged as a slash command.

This bot uses the [D++ library](https://github.com/brainboxdotcc/DPP). I run it on [replit](https://replit.com/), and D++'s docs [explain how to deploy in the same way](https://dpp.dev/building-a-cpp-discord-bot-in-repl.html) if you want to mess around with it without too much fuss or dependency management. Even more conveniently, said docs link to [dpp-on-repl](https://github.com/alanlichen/dpp-on-repl) if you want to take even more shortcuts.

If you're *not* running this bot on replit, you'll need to modify the code in `main.cpp` and replace all the references to environment variables with the much more straightforward method of simply writing your bot's token as a string on the initial call to `dpp::cluster()``. 
