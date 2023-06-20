BASE = mpl
BISON = bison
FLEX = flex
CFLAGS = -g # Flag for implicit rules. Turn on debug info

all: $(BASE) clean

%.c %.h: %.y
	$(BISON) $(BISONFLAGS) --header -o $*.c $<

%.c: %.l
	$(FLEX) $(FLEXFLAGS) -o$@ $<

lang.o: lang.c parse.h
#parse.o: parse.c
prep.o: prep.c
main.o: main.c prep.h
$(BASE): parse.o lang.o prep.o main.o
	$(CC) $(CFLAGS) -o $@ $^



CLEANFILES =						\
  *.o						\
  parse.[ch] parse.output parse.xml parse.html parse.gv	\
  lang.c
clean:
	rm -f $(CLEANFILES)
