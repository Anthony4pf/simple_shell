#SIMPLE SHELL IN C- AN IMPLEMENTATION OF UNIX COMMAND LINE INTERPRETER
A Shell is a program that takes the command inputs written from the user's stdin and passes them to the machine to execute them through the kernel. 

The Shell is can be a command-line interface or a graphical user interface that enables the user to use the services of the computerthrough system calls to the kernel.
In this repository, we will be implementing the Unix commandline interpreter.

##Simple Shell 0.1

The Shell will Display a prompt and wait for the user to type a command. A command line always ends with a new line.

The prompt is displayed again each time a command has been executed.

The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

The command lines are made only of one word. No arguments will be passed to programs.

If an executable cannot be found, print an error message and display the prompt again.

The Shell should Handle errors.

You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

	use the PATH

	implement built-ins

	handle special characters : ", ', `, \, *, &, #

	be able to move the cursor

	handle commands with arguments

execve is the core part of your Shell, don’t forget to pass the environ to it…
