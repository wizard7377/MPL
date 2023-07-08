BASE = mpl
BISON = bison
FLEX = reflex
BISONFLAGS = -rall -Dparse.trace --debug
CXXFLAGS = -g # Flag for implicit rules. Turn on debug info
FLEXFLAGS = -v -d -p -s

all: $(BASE) 

%.cpp %.hpp: grams/%.yy
	$(BISON) $(BISONFLAGS) --report-file=$*.txt --header -o $*.cpp $<

%.cpp %.hpp: grams/%.ll
	$(FLEX) $(FLEXFLAGS) -R --header-file=$*.hpp -o$@ $<

lang.o: lang.cpp parse.hpp 
cllang.o: cllang.cpp clparse.hpp 
parse.o: parse.cpp lang.hpp
clparse.o: clparse.cpp cllang.hpp back.hpp
prep.o: prep.cpp 
main.o: main.cpp parse.hpp lang.hpp structs.hpp back.hpp
back.o: back.cpp structs.hpp
clback.o: clback.cpp structs.hpp cllang.hpp clparse.hpp
$(BASE): cllang.o clparse.o lang.o parse.o main.o back.o clback.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -lreflex



CLEANFILES =						\
  *.o						\
  parse.cpp parse.hpp parse.output parse.xml parse.html parse.gv	\
  lang.cpp lang.hpp clparse.cpp clparse.hpp cllang.cpp cllang.hpp
clean:
	rm -f $(CLEANFILES)
