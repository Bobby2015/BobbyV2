#include "AST.h"

// Constructor
Node::Node()
{

}

// Destructor
Node::~Node()
{

}

// Get the left node
Node* Node::getLeftNode() 
{
	// Pointer to the left node
	return leftNode;
}

// Get the right node
Node* Node::getRightNode()
{
	// Pointer to the right node
	return rightNode;
}

string Node::getData()
{
	return nodeData;
}

NODE_TYPE Node::getType()
{
	return nodeType;
}