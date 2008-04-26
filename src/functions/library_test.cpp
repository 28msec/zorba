#include "functions/library.h"
#include "functions/Numerics.h"

using namespace std;
using namespace zorba;

signature op_add_sig;
op_numeric_add op_add;

int main(int argc, char* argv[])
{
	library lib;



	lib.put(
		functab_entry(
			new QName("fn1"),fn1,1,1,{ item() },item()));
	
}

