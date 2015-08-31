#pragma once

#ifndef PARSER_AST_H
#define PARSER_AST_H

#include <string>

using namespace std;

// Node type
enum NODE_TYPE {
	PROGRAM,
	PROCEDURE,
	STATEMENT_LIST,
	STATEMENT,
	IF,
	WHILE,
	CONSTANT
};

class Node 
{
public:
	Node();
	~Node();
	NODE_TYPE getType();
	Node* getLeftNode();
	Node* getRightNode();
	string getData();

private:
	NODE_TYPE nodeType;
	Node* leftNode;
	Node* rightNode;
	// Node data
	string nodeData;
};

#endif // PARSER_AST_H