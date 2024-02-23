CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = zombie_horde 

SRCS = main.cpp Zombie.cpp  

OBJDIR = obj
$(shell mkdir -p $(OBJDIR))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
