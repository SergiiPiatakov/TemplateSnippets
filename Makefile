CXX		= g++

.PHONY all: 001 002 003 004 \
			005 006 007 008 \
			009 010

001:
	$(CXX) -Wall -Wextra 001_main.cpp -o 001_main

002:
	$(CXX) -Wall -Wextra 002_main.cpp -o 002_main

003:
	$(CXX) -Wall -Wextra -std=c++11 003_main.cpp -o 003_main

004:
	$(CXX) -Wall -Wextra -std=c++11 004_main.cpp -o 004_main

005:
	$(CXX) -Wall -Wextra -std=c++11 005_main.cpp -o 005_main

006:
	$(CXX) -Wall -Wextra 006_main.cpp -o 006_main

007:
	$(CXX) -Wall -Wextra 007_main.cpp -o 007_main

008:
	$(CXX) -Wall -Wextra -std=c++11 008_main.cpp -o 008_main

009:
	$(CXX) -Wall -Wextra 009_main.cpp -Wno-unused-variable -o 009_main

010:
	$(CXX) -Wall -Wextra 010_main.cpp -std=c++11 -o 010_main

.PHONY clean:
	$(RM) 001_main
	$(RM) 002_main
	$(RM) 003_main
	$(RM) 004_main
	$(RM) 005_main
	$(RM) 006_main
	$(RM) 007_main
	$(RM) 008_main
	$(RM) 009_main
	$(RM) 010_main
