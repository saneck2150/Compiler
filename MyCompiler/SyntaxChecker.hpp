#include "include.hpp"
#include "Lexer.hpp"

namespace Compiler
{
	class SyntaxChecker : public Lexer
	{
	public:
		bool symbolCheck(vector<string>);
		bool grammarCheck(vector<string>);
		bool bracketCheck(vector<string>);
		bool semicolumnCheck(vector<string>);
		bool runSyntaxCheck(vector<string>);
	};
}