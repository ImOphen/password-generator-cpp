#include <iostream>

int main()
{
	std::string 	password;
	std::string 	input;
	int 			length;

	std::string 	alphabets 			= "abcdefghijklmnopqrstuvwxyz";
	std::string 	numbers				= "0123456789";
	std::string 	special_characters	= "!@#%?*";

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
		int random_number = rand() % 8;
		if (random_number <= 3)
			password += alphabets[rand() % alphabets.length()];
		else if (random_number < 6)
			password += numbers[rand() % numbers.length()];
		else
			password += special_characters[rand() % special_characters.length()];
	}
	std::cout << "Your generated password is : " << password << std::endl;
	system(("echo \"" +password + "\" | pbcopy").c_str());
	std::cout << "the password has been copied to your clipboard." << std::endl;
	return (0);
}