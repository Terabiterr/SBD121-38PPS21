#include <iostream>
#include "Compiler.h"

Compiler Assembly(Compiler compiler)
{
	for (int i = 0; i < compiler.GetCount(); i++)
	{
		cout << compiler.GetCodeDone()[i].GetCode() << endl; // show code
		compiler.GetCodeDone()[i].SetCode(""); // clear dome code
	}
	Compiler doneCompiler(compiler);
	return doneCompiler;
}

int main()
{
	const int size = 3;
	Code* code;
	code = new Code[size];
	code[0].SetName();
	code[0].SetCode();
	code[1].SetName("test.cpp");
	code[1].SetCode("#include \"Compiler.h\"");
	code[2].SetName("test1.cpp");
	code[2].SetCode("Compiler Assembly(Compiler compiler)");

	Compiler comp(code, size);
	comp.Assemble();

	Compiler cmd(Assembly(comp));
	if (cmd.GetCodeDone()->GetCode()._Equal("")) 
	{
		cout << "success!" << endl;
	}
}
