#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "functions.h"
#include "BinarySearchTree.h"

TEST_CASE( "Balanced test", "[stack]" ){
	std::string expression;
	char ch;
	std::fstream fin("./data/one.txt", std::fstream::in);
	while(fin >> noskipws >> ch){
		expression+=ch;
	}
	CHECK( balanced(expression) );

	expression = "";	
	std::fstream fin2("./data/two.txt", std::fstream::in);
	while(fin2 >> noskipws >> ch){
		expression+=ch;
	}
	CHECK ( !balanced(expression) );
}
