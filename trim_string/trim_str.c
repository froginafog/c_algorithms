#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * push_char(char * s, char ch)
{
	int i = 0;

	while(s[i] != '\0')
	{
		i++;
	}

	char * s_new = malloc(sizeof(char) * (i + 2));

	i = 0;
	while(s[i] != '\0')
	{
		s_new[i] = s[i];
        i++;
	}
	s_new[i] = ch;
	i++;
	s_new[i] = '\0';
	free(s);

	return s_new;
}

char * read_line()
{
	char * s = malloc(sizeof(char));
	char ch;

	while((ch = getchar()) != '\n')
	{
		s = push_char(s, ch);
	}

	return s;
}

char * trim_leading_spaces(char * s)
{
	int i;
	
	i = 0;
	while(s[i] == ' ' && s[i] != '\0')
	{
		i++;
	}

	char num_chars = strlen(s);
	char * s_new = malloc(sizeof(char) * (num_chars + 1 - i));
	int j = 0;
	
	while(s[i] != '\0')
	{
		s_new[j] = s[i];
		i++;
		j++;	
	}
	s_new[j] = '\0';
	
	return s_new;
}

char * trim_trailing_spaces(char * s)
{
	int i = 0;
	
	while(s[i] == ' ' && s[i] != '\0')
	{
		i++;
	} 	
	
	int position_of_last_non_space_char = 0;
	
	while(s[i] != '\0')
	{
		if(s[i] != ' ')
		{
			position_of_last_non_space_char = i;
		}
		i++;
	}
	
	char * s_new = malloc(sizeof(char) * (position_of_last_non_space_char + 1));
	
	for(i = 0; i <= position_of_last_non_space_char; i++)
	{
		s_new[i] = s[i];
	}
	s_new[i] = '\0';
	
	return s_new;
}

char * trim_leading_and_trailing_spaces(char * s)
{
	s = trim_leading_spaces(s);
	s = trim_trailing_spaces(s);
	
	return s;
}

char * trim_str(char * s)
{
	s = trim_leading_and_trailing_spaces(s);

	char ch;
	char previous_ch;
	int i;
	int j;
	
	char * s_new = malloc(sizeof(char) * (strlen(s) + 1));
	char * word = malloc(sizeof(char) * 50);
	
	i = 0;
	j = 0;
	previous_ch = s[i];
	while(s[i] != '\0')
	{	
		if(s[i] != ' ')
		{
			word[j] = s[i];
			i++;
			j++;
		}
		else
		{
			word[j] = ' ';
			j++;
			word[j] = '\0';
			j = 0;
			strcat(s_new, word);
			free(word);
			char * word = malloc(sizeof(char) * 50);
			
			while(s[i] == ' ')
			{
				i++;
			}
		}
	}
	
	//To append the last word in s to s_new.
	
	if(strcmp(word,".") == 0) 
	{
		s_new = trim_trailing_spaces(s_new);
		strcat(s_new, word);
	}
	else
	{
		strcat(s_new, word);
		free(word);
	}
	
	return s_new;
}

int main()
{
	char * s;

	printf("Enter a string:\n");
	s = read_line();
	s = trim_str(s);

	printf("The string after trimming:\n");
	printf("|%s|\n", s);

	return 0;
}

/*
Enter a string:
    To    C or    not to   C   .
The string after trimming:
|To C or not to C.|
*/



