IN_FILES = $(wildcard *.erl)
OUT_FILES = $(subst .erl,.beam,$(IN_FILES))
ERLC_FLAGS = +export_all

all: $(OUT_FILES)
	touch $(IN_FILES)

%.beam: %.erl
	erlc $(ERLC_FLAGS) -o $@ $<
