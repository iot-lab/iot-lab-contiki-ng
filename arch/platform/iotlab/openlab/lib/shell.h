#define COMMAND_LEN 256
#define MAX_ARGS_NUM 64

typedef int (*shell_cmd_handler_t)(int argc, char **argv);

struct shell_command {
    const char *name;
    const char *desc;
    shell_cmd_handler_t handler;
};

void shell_init(struct shell_command *cmds, int with_prompt);

int shell_handle_line(struct shell_command *cmds, char *line);

int shell_parse_line(char *line, char **argv, int max_argv);

