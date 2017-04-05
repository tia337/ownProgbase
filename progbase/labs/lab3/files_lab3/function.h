#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

  struct university{
   char full_name[150];
   char location[50];
   float success_level;
   int rank;
   struct {
    int students;
    int matan_points;
   } more_data;
 };

  int input_index();

  int file_pointer_for_fw();

  int file_write(struct university * ptr[]); //ready

  int file_process(const char *file_in, struct university * ptr[]); //ready

  char * input_country_additional(char input_country[]);

  int country_search(struct university * ptr[], char  input_country[]);

  void struct_fields_modify(struct university * ptr[]);

  void copy_struct(struct university * ptr[]);

  struct university *delete_from_struct(struct university * ptr[], int input); //ready

  void write_string_to_struct(struct university * ptr[]);

  void print_out(struct university * ptr[]);

  char scan_str(char *str);

  char scan_str_for5(char *str);

  void new_year_tree();
#endif
