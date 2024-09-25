**Simple Shell Project**

This repository contains the source code for a simple shell project written in C. The project includes the following components:

**Files:**

- **AUTHORS:** Lists the authors of the project.
- **README.md:** This file.
- **condition_function.c:** Implements functions for handling conditional statements.
- **display_format.c:** Implements functions for formatting and displaying output.
- **load_shell.c:** Implements functions for parsing and loading commands.
- **output_format.c:** Implements functions for handling input and output.
- **shell.h:** Header file containing constants, macros, and function prototypes.
- **startup_os.c:** Implements functions for launching processes.
- **super_shell.c:** Main entry point for the shell.
- **userexp_useless.c:** Implements functions for handling user experience issues.

**Features:**

- **Command parsing:** The shell can parse and execute simple commands.
- **Built-in commands:** The shell includes built-in commands such as `env` and `quit`.
- **External commands:** The shell can execute external commands using the `execve` system call.
- **Path searching:** The shell can search for external commands in the `PATH` environment variable.
- **Redirection:** The shell supports input and output redirection using the `<` and `>` operators.
- **Piping:** The shell supports piping, which allows the output of one command to be used as input for another.
- **Error handling:** The shell can handle certain errors, such as invalid commands and permission denied.

**Usage:**

To use the shell, clone the repository and compile the source code using a C compiler such as `gcc`. Then, run the executable file to start the shell.

**Limitations:**

The shell is a simple project and does not have all the features of a fully-fledged shell, such as job control or scripting.

**Contributions:**

Contributions are welcome. Please create a pull request if you have any improvements or fixes.