#include <iostream>

int main()
{
	std::string 	password;
	std::string 	input;
	int 			length;
	
	std::string 	alphabets 			= "abcdefghijklmnopqrstuvwxyz";
	std::string 	numbers				= "0123456789";
	std::string 	special_characters	= "!@#%^&?*()";

	std::cout << "How long do you want your password to be ? : ";
	std::getline(std::cin, input);
	try
	{
		length = std::stoi(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		int random_number = rand() % 3;
		if (random_number == 0)
		{
			int random_number_2 = rand() % alphabets.length();
			password += alphabets[random_number_2];
		}
		else if (random_number == 1)
		{
			int random_number_2 = rand() % numbers.length();
			password += numbers[random_number_2];
		}
		else if (random_number == 2)
		{
			int random_number_2 = rand() % special_characters.length();
			password += special_characters[random_number_2];
		}
	}
	std::cout << "Your generated password is : " << password << std::endl;
	system(("echo \"" +password + "\" | pbcopy").c_str());
	std::cout << "the password has been copied to your clipboard." << std::endl;
	return (0);
}