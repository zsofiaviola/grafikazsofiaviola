#include <obj/load.h>

int main(int argc, char* argv[])
{
	Model model;
	
	load_model(&Model, "porsche.obj");
	return 0;
}