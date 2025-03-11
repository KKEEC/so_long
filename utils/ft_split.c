#include "../so_long.h"


int	count_words(const char *str, char c)
{
	int	count = 0;
	int	i = 0;

	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strndup(const char *str, int start, int len)
{
	char	*word;
	int		i = 0;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**words;
	int		i = 0, j = 0, start = 0;
	int		word_count = count_words(str, c);

	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		if (start < i)
			words[j++] = ft_strndup(str, start, i - start);
	}
	words[j] = NULL;
	return (words);
}
