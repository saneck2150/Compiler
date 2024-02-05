#include "include.hpp"

namespace Compiler
{
	class Token
	{
	public:
		TokenType Ttype	{};
		string lexemVar	{""};
		int lexemNum	{};
	};

	class ASTNode
	{
	public:
		ASTNodeType ASTNtype		{};
		vector<ASTNode> ASTNBranch	{};
		Token token					{};
	};
}
