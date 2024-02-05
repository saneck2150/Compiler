#pragma once
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

namespace Compiler
{
	class Lexer;
	class Parser;
	class ASTNode;
	class Token;
	class ParserNodes;

	const enum TokenType
	{
		INT,
		ELSE,
		WHILE,
		IF,
		LBRA,
		RBRA,
		LPAR,
		RPAR,
		EQUAL,
		LESS,
		PLUS,
		MINUS,
		SEMICOLUMN,
		NUM,
		VAR
	};

	const map<TokenType, string> TokenTypeValue
	{
		{INT,		"INT"},
		{ELSE,		"ELSE"},
		{WHILE,		"ELSE"},
		{IF,		"IF"},
		{LBRA,		"LBRA"},
		{RBRA,		"RBRA"},
		{LPAR,		"LPAR"},
		{RPAR,		"RPAR"},
		{EQUAL,		"EQUAL"},
		{LESS,		"LESS"},
		{PLUS,		"PLUS"},
		{MINUS,		"MINUS"},
		{SEMICOLUMN,"SEMICOLUMN"},
		{NUM,		"NUM"},
		{VAR,		"VAR"}

	};

	const enum ASTNodeType 
	{
		Program,
		IfStatement,
		WhileStatement,
		Assignment,
		Expression,
		Term,
		Number,
		Variable
	};
}