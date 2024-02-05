#include "MyParser.hpp"

namespace Compiler
{
	ASTNode Compiler::Parser::parseProgram()
	{
		ASTNode programNode;
		programNode.ASTNtype = ASTNodeType::Program;

		return ASTNode();
	}

	ASTNode Parser::parseIfStatement()
	{
		ASTNode ifStatementNode;
		ifStatementNode.ASTNtype = ASTNodeType::IfStatement;

		while (1)
		{
			currentTokenIndex++;
		}

		return ASTNode();
	}

	TokenType Parser::getCurrentToken()
	{
		return TokenType();
	}

	TokenType Parser::getNextToken()
	{
		if (currentTokenIndex < parserIn.size())
		{
			return parserIn[currentTokenIndex++];
		}
		else
		{
			return TokenType();
		}
	}

	bool Parser::syntaxMatchCheck(TokenType expectedType)
	{
		return false;
	}
}