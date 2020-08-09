#include <discpp/client.h>
#include <discpp/context.h>

#include <discpp/event_handler.h>
#include <discpp/events/ready_event.h>
#include <discpp/client_config.h>

#include <fstream>

int main(int argc, const char* argv[])
{
	std::cout << "Initializing bot!" << std::endl;
	std::ifstream token_file("D:\\Projects\\Playground\\ZedBot\\token.txt");
	std::string token;
	std::getline(token_file, token);
	std::cout << "Token: " << token << std::endl;
	discpp::ClientConfig* config = new discpp::ClientConfig({ "!" });
	discpp::Client bot{ token, config };
	std::cout << "Bot initalized!" << std::endl;

	discpp::EventHandler<discpp::ReadyEvent>::RegisterListener(
		[&bot](discpp::ReadyEvent event)
		{
			std::cout << "Ready!" << std::endl;
		}
	);

	return bot.Run();
}