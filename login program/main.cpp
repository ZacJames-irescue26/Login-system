#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//login system
// need a way to register and create a file.
//need a way to check for the correct login from a file
void Register();
void Login();
bool Running = true;
int main()
{
	
	while (Running)
	{


		std::cout << "Welcome" << std::endl;
		std::cout << "1: Login" << std::endl;
		std::cout << "2: Register" << std::endl;
		std::cout << "3: Exit" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			Login();
			break;
		case 2:
			Register();
			break;
		case 3:
			Running = false;
			return 0;
			break;
		default:
			std::cout << "Enter a correct number" << std::endl;
			break;
		}
	}
}

void Register()
{
	std::cout << "Enter your username: " << std::endl;
	std::string Username;
	std::cin >> Username;
	std::cout << "Enter your password: " << std::endl;
	std::string Password;
	std::cin >> Password;

	std::fstream RegisterFile;
	RegisterFile.open("Register.txt");
	if (RegisterFile.is_open())
	{
		std::string check;

		while (std::getline(RegisterFile, check))
		{
			if (check == (Password + Username))
			{
				
				std::cout << "username and password already exists" << std::endl;
				
			}
			std::cout << check << std::endl;
		}
		std::ofstream ofRegisterFile;
		ofRegisterFile.open("Register.txt", std::ios::app);

		ofRegisterFile <<Username + Password + "\n";
		std::cout << "Account made" << std::endl;
		ofRegisterFile.close();
	}
	else 
	{
		std::cout << "failed to open file" << std::endl;
	}
	
	
	

	RegisterFile.close();
}

void Login()
{
	std::fstream RegisterFile;
	RegisterFile.open("Register.txt");
	std::cout << "Username:" << std::endl;
	std::string username;
	std::cin >> username;
	std::cout << "Password" << std::endl;
	std::string password;
	std::cin >> password;
	if (RegisterFile.is_open())
	{
		std::string check;
		while (getline(RegisterFile, check))
		{
			if (check == (password + username))
			{
				std::cout << "Logged in" << std::endl;
				Running = false;
				return;
			}

			std::cout << check << std::endl;
		}
		std::cout << "Incorrect password or login" << std::endl;
		
	}
	else
	{
		std::cout << "failed to open file" << std::endl;
	}
}