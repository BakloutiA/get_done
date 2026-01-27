#include "get_next_line.h"

char	*update_box(char *box)
{
	int		i;
	int		j;
	char	*new_box;

	i = 0;
	while (box[i] && box[i] != '\n')
		i++;
	if (!box[i])
	{
		free(box);
		return (NULL);
	}
	new_box = malloc(sizeof(char) * (ft_strlen(box) - i + 1));
	if (!new_box)
		return (NULL);
	i++;
	j = 0;
	while (box[i])
		new_box[j++] = box[i++];
	new_box[j] = '\0';
	free(box);
	return (new_box);
}

char	*extract_line(char *box)
{
	int		i;
	char	*str;

	i = 0;
	if (!box[i])
		return (NULL);
	while (box[i] && box[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (box[i] && box[i] != '\n')
	{
		str[i] = box[i];
		i++;
	}
	if (box[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*box;
	char		*line;
	char		*buffer;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(box, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		box = ft_strjoin(box, buffer);
	}
	free(buffer);
	line = extract_line(box);
	box = update_box(box);
	return (line);
}
