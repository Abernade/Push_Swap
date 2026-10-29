_This project has been created as part of the 42 curriculum by vldryga._

## Description

The goal of the Libft's project is to reimplement some useful standard library functions, but also string and linked lists manipulation functions. It provides a reusable library for the next C 42 projects.

## Instructions

If you want to use it, you must compile it with the command `make` in the CLI/terminal from the root repository : it will create `libft.a` file.
If you modify a function in a .c file, you'll need to recompile it so you'll need `make re` command that suppresses object files created to generate the libft.a and recreates it.
If you no longer need, the object files you can supresse them using the command `make clean`.

## Resources

Among the resources used : the `man 3` for the functions of libc from the terminal.

#### Makefile : [GNU make](https://www.gnu.org/software/make/manual/make.html)

#### For the markdown (.md) : [Markdown Cheat-Sheet](https://onlinemarkdown.com/cheat-sheet)

#### For the linked-list : [GeekForGeeks](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/) , [pdf of ESIEE's course](https://perso.esiee.fr/~djebalia/algo2/intro-liste.pdf)

## Detailed Functions

#### Standard functions

These functions were implemented with the prefix **ft_** before each of then (**ft** means forty-two !): isalpha, isdigit, isalnum, isascii, isprint, strlen, memset, bzero, memcpy, memmove, strlcpy, strlcat, toupper, tolower, strchr, strrchr, strncmp, memchr, memcmp, strnstr, atoi, strdup and calloc (with the following rule : '_If nmemb or size is 0, then calloc() returns a unique pointer value that can be successfully passed to free()._'). All of them works as the man requires.

#### Additionnal functions

These ones are not included in _libc_:

- ft_substr : returns the substring of a string; NULL if memory allocation fails
- ft_strjoin : concatenates two string in one allocating memory
- ft_strtrim : trims the beggining and the end of a string
- ft_split : splits a string in multiples strings stored in a double pointer char
- ft_itoa : converts an integer in its string representation
- ft_strmapi : applies a function passed in parameter to each character of the string, passing its index as first argument and then the character itself
- ft_striteri : applies a function passed in parameter to each character of the string, passing its index as first argument and then the pointer to each char so it can be modified in the string.
- ft_putchar_fd : allows to write a character in the wanted file descriptor
- ft_putstr_fd : allows to write a string of characters in the wanted file descriptor
- ft_putendl_fd : allows to write a string followed by a new line in the wanted file descriptor
- ft_putnbr_fd : allows to write an integer int the wanted file descriptor

#### Linked-list's related functions

These functions work with the defined structure `t_list`. Each structure contains a void pointer that contains the content of the node (_item_), and a pointer of type `t_list` that point to the next node/t_list structure.

- ft_lstadd_back : adds a new node at the end of the node's list
- ft_lstadd_front : adds a new node at the beggining of the list
- ft_lstclear : deletes a node's list fully
- ft_lstdelone : deletes the content and frees a node (it will not relink the previous node with the next one !)
- ft_lstiter : iterates the content of a node's list by function `f`
- ft_lstlast : returns the last node of the linked list
- ft_lstmap : creates a modified version of the linked list with modified content by function `f` and deletes the source node with `del` function
- ft_lstnew : creates a new node
- ft_lstsize : returns the numbers of the nodes in the given list
