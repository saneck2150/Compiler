#include "Lexer.hpp"

const int L_BOUND_ASCII_LETTER = 65;
const int U_BOUND_ASCII_LETTER = 90;

const int L_BOUND_ASCII_NUMBER = 48;
const int U_BOUND_ASCII_NUMBER = 57;


namespace Compiler
{
	vector<TokenType>Lexer::s_lexerOut			{};
	string			 Lexer::s_lexerIn			{ "" };
	bool			 Lexer::s_lexerErrorStatus	{ 0 };
	const int		 Lexer::s_lexerInMaxRange	{ 1000 };
	vector<int>		 Lexer::s_valueSequence		{};
	vector<char>	 Lexer::s_varSequence		{};

//=================================================

	void Lexer::getCode()
	{
		string usersInput = "";

		try // error handling for user's input
		{
			while (1)
			{
				cin >> usersInput;

				if (usersInput == "/c") break;
				if (usersInput.length() > s_lexerInMaxRange) throw string( "Youre out of range limit for one input (max 1000 symb.)" );

				s_lexerIn += usersInput;
				usersInput = "";
			}
		}
		catch (string ex)
		{
			cout << "Error with Input\n";
			cout << "Youre out of range limit for one input";
		}
		catch (...)
		{
			cout << "Error with Input\n";
		}
	}

	void Lexer::transformToVC()
	{
		auto posIf = s_lexerIn.find("if");
		auto posWhile = s_lexerIn.find("while");
		auto posElse = s_lexerIn.find("else");
		auto posInt = s_lexerIn.find("int");
		int	 valIdx = 0;

		for (auto it = s_lexerIn.begin(); it != s_lexerIn.end(); it++)
		{
			// Key words
			if (distance(s_lexerIn.begin(), it) == posIf)
			{
				s_lexerOut.push_back(TokenType::IF);
				posIf = s_lexerIn.find("if", posIf + 2);
			}

			if (distance(s_lexerIn.begin(), it) == posWhile)
			{
				s_lexerOut.push_back(TokenType::WHILE);
				posWhile = s_lexerIn.find("while", posWhile + 5);
			}

			if (distance(s_lexerIn.begin(), it) == posElse)
			{
				s_lexerOut.push_back(TokenType::ELSE);
				posElse = s_lexerIn.find("else", posElse + 4);
			}

			if (distance(s_lexerIn.begin(), it) == posInt)
			{
				s_lexerOut.push_back(TokenType::INT);
				posInt = s_lexerIn.find("int", posInt + 2);
			}
			
			// Symbols
			if (*it == '{') s_lexerOut.push_back(TokenType::LBRA);
			if (*it == '}') s_lexerOut.push_back(TokenType::RBRA);
			if (*it == '(') s_lexerOut.push_back(TokenType::LPAR);
			if (*it == ')') s_lexerOut.push_back(TokenType::RPAR);
			if (*it == '=') s_lexerOut.push_back(TokenType::EQUAL);
			if (*it == '<') s_lexerOut.push_back(TokenType::LESS);
			if (*it == '+') s_lexerOut.push_back(TokenType::PLUS);
			if (*it == '-') s_lexerOut.push_back(TokenType::MINUS);
			if (*it == ';') s_lexerOut.push_back(TokenType::SEMICOLUMN);

			// Variable names
			if (*it >= L_BOUND_ASCII_LETTER && *it <= U_BOUND_ASCII_LETTER)
			{
				s_lexerOut.push_back(TokenType::VAR);
				s_varSequence.push_back(*it);
			}
			// Values
			if (*it >= L_BOUND_ASCII_NUMBER && *it <= U_BOUND_ASCII_NUMBER)
			{
				s_lexerOut.push_back(TokenType::NUM);
				s_valueSequence.push_back(*it - char('0'));
			}
		}
	}
}