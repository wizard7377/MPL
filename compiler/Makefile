BASE = mpl
BISON = bison
FLEX = reflex
BISONFLAGS = -rall --report-file=file4.txt -Dparse.trace
CXXFLAGS = -g # Flag for implicit rules. Turn on debug info
FLEXFLAGS = -v  -p -s

all: $(BASE) clean

%.cpp %.hpp: %.yy
	$(BISON) $(BISONFLAGS) --header -o $*.cpp $<

%.cpp %.hpp: %.ll
	$(FLEX) $(FLEXFLAGS) -R --header-file=lang.hpp -o$@ $<

lang.o: lang.cpp parse.hpp 
parse.o: parse.cpp lang.hpp
prep.o: prep.cpp 
main.o: main.cpp parse.hpp lang.hpp structs.hpp back.hpp
back.o: back.cpp structs.hpp
$(BASE): lang.o parse.o main.o back.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lreflex



CLEANFILES =						\
  *.o						\
  parse.cpp parse.hpp parse.output parse.xml parse.html parse.gv	\
  lang.cpp lang.hpp 
clean:
	rm -f $(CLEANFILES)
