if [ -d "usr" ]
then
	export LD_LIBRARY_PATH=/home/runner/$REPL_SLUG/usr/lib:$LD_LIBRARY_PATH
	g++ -std=c++17 src/*.cpp -o bot -L./usr/lib -I./usr/include -ldpp -lpthread
	./bot & python -m http.server
else
	curl -L https://github.com/brainboxdotcc/DPP/releases/download/v9.0.16/libdpp-9.0.16-linux-x64.deb > dpp.deb
	dpkg -x dpp.deb .
	rm dpp.deb
	clear
	echo Successfully installed D++ and netcat. Please re-run your repl to start the bot.
fi