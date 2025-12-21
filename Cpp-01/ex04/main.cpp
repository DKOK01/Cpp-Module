/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:00:00 by aysadeq           #+#    #+#             */
/*   Updated: 2025/12/21 00:00:00 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Replaces all occurrences of s1 with s2 in the given content
 * 
 * This function manually implements string replacement without using
 * std::string::replace(). It iterates through the content string, finds
 * each occurrence of s1, and builds a new string with s2 in place of s1.
 * 
 * Algorithm:
 * 1. Start from position 0
 * 2. Search for s1 using std::string::find()
 * 3. If found, copy everything before s1, then add s2
 * 4. Move position past the found s1
 * 5. Repeat until no more occurrences found
 * 6. Add remaining content after last occurrence
 * 
 * @param content The original string content
 * @param s1 The string to search for and replace
 * @param s2 The string to replace s1 with
 * @return std::string The modified content with all replacements made
 */
std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;        // Current position in the content string
	size_t found;          // Position where s1 is found

	// Loop through content, finding each occurrence of s1
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		// Append everything from current position to just before s1
		// substr(pos, found - pos) extracts substring from pos with length (found - pos)
		result += content.substr(pos, found - pos);
		
		// Append s2 instead of s1
		result += s2;
		
		// Move position past the occurrence of s1
		// This ensures we don't process the same s1 again
		pos = found + s1.length();
	}
	
	// Append remaining content after the last occurrence of s1
	// substr(pos) extracts from pos to end of string
	result += content.substr(pos);

	return result;
}

/**
 * @brief Main function that handles file reading, string replacement, and writing
 * 
 * Expected usage: ./replace <filename> <s1> <s2>
 * - Opens <filename> for reading
 * - Replaces all occurrences of s1 with s2
 * - Writes result to <filename>.replace
 * 
 * Error handling:
 * - Validates number of arguments
 * - Checks if s1 is empty (would cause infinite loop)
 * - Verifies input file can be opened
 * - Verifies output file can be created
 * 
 * @param argc Number of command-line arguments (should be 4)
 * @param argv Array of command-line arguments
 * @return int Exit status (0 = success, 1 = error)
 */
int main(int argc, char** argv)
{
	// Validate command-line arguments
	// argc should be 4: program name, filename, s1, s2
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	// Store arguments in variables for clarity
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Check if s1 is empty - this would cause infinite loop in replaceAll
	// because find() would always match at current position
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	// Open input file for reading
	// c_str() converts std::string to const char* (required for C++98)
	std::ifstream inputFile(filename.c_str());
	
	// Check if file was successfully opened
	// Common failures: file doesn't exist, no read permission
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
		return 1;
	}

	// Read entire file content into a string
	// We use getline() in a loop to preserve line structure
	std::string content;
	std::string line;
	
	// Read file line by line
	while (std::getline(inputFile, line))
	{
		content += line;
		
		// Add newline character after each line, except the last one
		// eof() returns true only after attempting to read past end of file
		if (!inputFile.eof())
			content += "\n";
	}
	
	// Close input file - good practice to explicitly close files
	inputFile.close();

	// Perform the string replacement
	std::string result = replaceAll(content, s1, s2);

	// Create output filename by appending ".replace" to original filename
	std::string outputFilename = filename + ".replace";
	
	// Open output file for writing
	// This creates a new file or overwrites existing file
	std::ofstream outputFile(outputFilename.c_str());
	
	// Check if output file was successfully created
	// Common failures: no write permission, disk full, invalid path
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot create file '" << outputFilename << "'" << std::endl;
		return 1;
	}

	// Write the modified content to output file
	outputFile << result;
	
	// Close output file
	outputFile.close();

	// Inform user of successful completion
	std::cout << "File created successfully: " << outputFilename << std::endl;
	
	return 0;
}
