#include "sha512.hpp"

int main(int argc,char** argv){

  char cstring[] = "Foo baz, testing.";
	std::string str = cstring;

	/* SHA512 from std::string */
	printf("sha512sum: %s\n\n",  sha512( str ).c_str());

	/* SHA512 from c-string */
	printf("sha512sum: %s\n\n",  sha512( cstring, strlen(cstring) ).c_str());

	/* SHA512 from filename */
	printf("sha512file: %s\n\n", sha512file("lzma.lib").c_str());

	/* SHA512 from opened file */
	std::FILE* file = std::fopen("lzma.lib", "rb");
	printf("sha512file: %s\n\n", sha512file(file).c_str());
	std::fclose(file);

  /* we're done */
  return EXIT_SUCCESS;
}