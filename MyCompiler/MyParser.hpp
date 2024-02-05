#pragma once
#include "ParserNodes.hpp"

namespace Compiler
{
	class Parser
	{
		vector<TokenType> parserIn{};
		size_t currentTokenIndex{0};

		ASTNode parseProgram();
		ASTNode parseIfStatement();
		ASTNode	parseWhileStatement();
		ASTNode	parseAssignment();
		ASTNode	parseExpression();
		ASTNode	parseTerm();
		ASTNode	parseNumber();
		ASTNode	parseVariable();

		TokenType getCurrentToken();
		TokenType getNextToken();

		bool syntaxMatchCheck(TokenType expectedType);
	};
}
