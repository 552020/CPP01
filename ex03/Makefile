CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = unnecessary_violence

SRCS = main.cpp  HumanA.cpp HumanB.cpp Weapon.cpp HumanC.cpp

OBJDIR = obj
$(shell mkdir -p $(OBJDIR))

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
