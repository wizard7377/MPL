BASE = mpl
BISON = bison
FLEX = reflex
CXXFLAGS = -g # Flag for implicit rules. Turn on debug info

all: $(BASE) clean

%.cpp %.hpp: %.yy
	$(BISON) $(BISONFLAGS) -t --header -o $*.cpp $<

%.cpp %.hpp: %.ll
	$(FLEX) -x -R --header-file=lang.hpp -o$@ $<

lang.o: lang.cpp parse.hpp 
parse.o: parse.cpp lang.hpp
prep.o: prep.cpp 
main.o: main.cpp 
$(BASE): lang.o parse.o main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lreflex



CLEANFILES =						\
  *.o						\
  parse.cpp parse.hpp parse.output parse.xml parse.html parse.gv	\
  lang.cpp lang.hpp 
clean:
	rm -f $(CLEANFILES)
