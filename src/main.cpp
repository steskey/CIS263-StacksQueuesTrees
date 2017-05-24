#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "functions.h"

TEST_CASE( "Balanced test", "[stack]" ){
	std::string expression;
	char ch;
	std::fstream fin("./data/one.txt", std::fstream::in);
	while(fin >> std::noskipws >> ch){
		expression+=ch;
	}
	CHECK( balanced(expression) );

	expression = "";	
	std::fstream fin2("./data/two.txt", std::fstream::in);
	while(fin2 >> std::noskipws >> ch){
		expression+=ch;
	}
	CHECK ( !balanced(expression) );
}

TEST_CASE( "Evaluate expression test", "[bt]" ){
	Node<char>* root = new Node;
	root->data = "+";
	Node<char>* lc = new Node;
	lc->data = "3";
	Node<char>* rc = new Node;
	rc->data = "11";
	root->lc = lc;
	root->rc = rc;	
}
