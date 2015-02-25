#ifndef _FILE_GEST_
#define _FILE_GEST_
int req_pipe_gest(int *pipefd, int in_out);
void search_folder(char *namefile);
void del_file(char *namefile);
void add_file(char *namefile, char *file);
char *search_id_folder(char *namefile);
t_json *all_id_folder();
void write_tab_id(int fd_out);
void write_file_tab_id();
void write_all();
void write_all_name();
t_json *file_json();
void ft_wait();
#endif
