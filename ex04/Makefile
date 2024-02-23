CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = sed_is_for_losers 

SRCS = main.cpp 

OBJDIR = obj
$(shell mkdir -p $(OBJDIR))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean_replace:
	rm -f tests/test_files/*.replace

clean: clean_replace
	rm -rf $(OBJDIR)
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
