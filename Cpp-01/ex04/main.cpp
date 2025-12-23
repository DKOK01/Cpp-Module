#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	return result;
}

bool validateArguments(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return false;
	}

	std::string s1 = argv[2];
	std::string filename = argv[1];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return false;
	}

	if (filename.empty())
	{
		std::cerr << "Error: filename cannot be empty" << std::endl;
		return false;
	}

	return true;
}

bool readFile(const std::string& filename, std::string& content)
{
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += "\n";
	}

	inputFile.close();
	return true;
}

bool writeFile(const std::string& filename, const std::string& content)
{
	std::ofstream outputFile(filename.c_str());

	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot create file '" << filename << "'" << std::endl;
		return false;
	}

	outputFile << content;
	outputFile.close();

	std::cout << "File created successfully: " << filename << std::endl;
	return true;
}

int main(int argc, char** argv)
{
	if (!validateArguments(argc, argv))
		return 1;

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::string content;
	if (!readFile(filename, content))
		return 1;

	std::string result = replaceAll(content, s1, s2);

	std::string outputFilename = filename + ".replace";
	if (!writeFile(outputFilename, result))
		return 1;

	return 0;
}
