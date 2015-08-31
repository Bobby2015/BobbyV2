#pragma once

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <iostream>
#include <string>
#include <regex>
#include <locale>

class Parse
{
	public:
		Parse();
		~Parse();
		int add(unsigned x, unsigned y);

		// validate concrete syntax of the source code, return true if valid syntax, otherwise false
		bool concreteSyntaxValidator(std::string);

	private:
		unsigned first;
		unsigned second;
		
}; // Parse

#endif  // PARSER_PARSER_H


