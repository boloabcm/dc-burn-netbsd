#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  FILE *in, *out;
  int n, ch;
  
  if (argc < 4)
  {
    fprintf(stderr, "usage: %s <binary_input_file> <c_output_file> <c_variable_name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  in=fopen(argv[1], "rb");
  if (in == NULL)
  {
    fprintf(stderr, "Unable to open '%s'.\n", argv[1]);
    exit(EXIT_FAILURE);
  }


  out=fopen(argv[2], "wt");
  if (out == NULL)
  {
    fprintf(stderr, "Unable to open '%s'.\n", argv[2]);
    fclose(in);
    exit(EXIT_FAILURE);
  }
  
  fprintf(out, "unsigned char %s[] = {\n\t", argv[3]);
  
  n = 0;
  while ((ch = fgetc(in))!=EOF)
  {
    fprintf(out, "0x%02X, ", ch);
    n++;
    if (n > 16)
    { 
      fprintf(out, "\n\t");
      n = 0;
    }
  }
  fprintf(out, "\n};\n");
  fclose(out);
  fclose(in);
  exit(EXIT_SUCCESS);
}
