#include "include.hpp"

namespace Compiler
{
	class Lexer
	{
	public:
		static vector<TokenType>	s_lexerOut;
		static string				s_lexerIn;
		static bool					s_lexerErrorStatus;
		static const int			s_lexerInMaxRange;
		static vector<int>			s_valueSequence;
		static vector<char>			s_varSequence;

		static void getCode();
		static void transformToVC();
	};
}
