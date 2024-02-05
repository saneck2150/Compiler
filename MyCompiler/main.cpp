#include "Lexer.hpp"
using namespace Compiler;

int main()
{
	cout << "LEXER IN: \n\n";
	cout << "To stop writting code type /c then press Enter\n";
	cout << "Type your code here :\n";
	Lexer::getCode();
	cout << "\n\n\n" << Lexer::s_lexerIn;
	cout << "\n\n";
	Lexer::transformToVC();

	cout << "LEXER OUT:\n";
	for (auto it : Lexer::s_lexerOut)
	{
		auto mapIt = TokenTypeValue.find(it);
		cout << mapIt->second << endl;
	}

	cout << "\n\nPARSER: \n";
	return 0;
}