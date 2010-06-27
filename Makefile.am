AM_YFLAGS = -d
BUILT_SOURCES=parser.h

lib_LTLIBRARIES = libparsley.la
libparsley_la_SOURCES = parsed_xpath.c xml2json.c regexp.c functions.c util.c scanner.l parser.y parsley.c
include_HEADERS = parsley.h xml2json.h parsed_xpath.h

bin_PROGRAMS = parsleyc parsley

parsleyc_SOURCES = parsleyc_main.c
parsleyc_LDADD = libparsley.la

parsley_SOURCES = parsley_main.c
parsley_LDADD = libparsley.la

valgrind:
	./libtool --mode=execute valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./parsley test/fictional.let test/fictional.html

profile:
	./libtool --mode=execute valgrind --tool=callgrind ./parsley test/fictional.let test/fictional.html

install-all:
	./bootstrap.sh && ./configure && make && make install && cd ruby && rake install && cd ../python && python setup.py install
	
bench:
	@echo "yelp..."; ./parsley test/yelp.let test/yelp.html > /dev/null
	@echo "craigs-simple..."; ./parsley test/craigs-simple.let test/craigs-simple.html > /dev/null
	@echo "yelp-home..."; ./parsley test/yelp-home.let test/yelp-home.html > /dev/null
	@echo "craigs..."; ./parsley test/craigs.let test/craigs.html > /dev/null

check-am:
	(cd test && bash runtests.sh)
