PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

COMMON_ROOT = $(PROJECT_ROOT)../../message_common/

NAME = message_service
MESSAGE_SERVICE = MessageService
DATABASE_ADAPTER = DatabaseAdapter
PAYLOAD_OBJECT = Payload
CONFIG_MANAGER = ConfigManager
MESSAGE_NODE = MessageNode
OBJS = $(FILE_NAME).o
BUILD_MODE=run

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g -Iinclude
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2 -Wall -Iinclude
else ifeq ($(BUILD_MODE),linuxtools)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage -Iinclude
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

OBJDIR = $(mkfile_dir)obj
BINDIR = $(mkfile_dir)bin
SRCDIR = $(mkfile_dir)src
OBJS = $(OBJDIR)/$(NAME).o

MESSAGE_SERVICE_OBJ = $(OBJDIR)/$(MESSAGE_SERVICE).o
DATABASE_ADAPTER_OBJ = $(OBJDIR)/$(DATABASE_ADAPTER).o
PAYLOAD_OBJECT_OBJ = $(OBJDIR)/$(PAYLOAD_OBJECT).o
CONFIG_MANAGER_OBJ = $(OBJDIR)/$(CONFIG_MANAGER).o
MESSAGE_NODE_OBJ = $(OBJDIR)/$(MESSAGE_NODE).o

$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p $(BINDIR))

all:	$(BINDIR)/$(NAME)

$(BINDIR)/$(NAME):	$(OBJS) $(MESSAGE_SERVICE_OBJ) $(DATABASE_ADAPTER_OBJ) $(PAYLOAD_OBJECT_OBJ) $(CONFIG_MANAGER_OBJ) $(MESSAGE_NODE_OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ -ltbb --std=c++17 -lpaho-mqtt3as -lpaho-mqttpp3 -lmysqlcppconn
$(OBJS):	$(PROJECT_ROOT)src/main.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17
$(MESSAGE_SERVICE_OBJ): $(PROJECT_ROOT)src/$(MESSAGE_SERVICE).cpp $(PROJECT_ROOT)src/$(MESSAGE_SERVICE).h
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17 -lmysqlcppconn

#COMMON -
$(DATABASE_ADAPTER_OBJ): $(COMMON_ROOT)src/$(DATABASE_ADAPTER).cpp $(COMMON_ROOT)src/$(DATABASE_ADAPTER).h
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17 -lmysqlcppconn
	
$(PAYLOAD_OBJECT_OBJ): $(COMMON_ROOT)src/$(PAYLOAD_OBJECT).cpp $(COMMON_ROOT)src/$(PAYLOAD_OBJECT).h
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17 -lrapidjson

$(CONFIG_MANAGER_OBJ): $(COMMON_ROOT)src/$(CONFIG_MANAGER).cpp $(COMMON_ROOT)src/$(CONFIG_MANAGER).h
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17 -lrapidjson
	
$(MESSAGE_NODE_OBJ): $(COMMON_ROOT)src/$(MESSAGE_NODE).cpp $(COMMON_ROOT)src/$(MESSAGE_NODE).h
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< -ltbb --std=c++17 -lrapidjson

clean:
	rm -rf -v $(OBJDIR) $(BINDIR)
