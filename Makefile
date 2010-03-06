CC = $(CROSS_COMPILE)gcc
STRIP  = $(CROSS_COMPILE)strip
CFLAGS = -O2 -imacros $(CURDIR)/macros.h -D__nucleos__

PROGS = test1  test2  test3  test4  test5  test6  test7  test8  test9  test10 \
	test11 test12 test13 test14 test15 test16 test17 test18 test19 test20 \
	test21 test22 test23 test24 test25 test26 test27 test28 test29 test30 \
	test31 test32 test33 test34 test35 test36 test37 test38        test40 \
	test41        test43 test44 test45 test46 \
	t10a \
	t11a t11b \
	t40a t40b t40c t40d t40f \
	test_uname \
	hello \
	test_gettimeofday \
	test_getenv \
	test_creat \
	statcheck
# test43 test44

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test1: test1.o
test2: test2.o
test3: test3.o
test4: test4.o
test5: test5.o
test6: test6.o
test7: test7.o
test8: test8.o
test9: test9.o
test10: test10.o
test11: test11.o
t10a: t10a.o
t11a: t11a.o
t11b: t11b.o
test12: test12.o
test13: test13.o
test14: test14.o
test15: test15.o
test16: test16.o
test17: test17.o
test18: test18.o
test19: test19.o
test20: test20.o
test21: test21.o
test22: test22.o
test23: test23.o
test24: test24.o
test25: test25.o
test26: test26.o
test27: test27.o
test28: test28.o
test29: test29.o
test30: test30.o
test31: test31.o
test32: test32.o
test33: test33.o
test34: test34.o
test35: test35.o
test36: test36.o
test37: test37.o
test38: test38.o
test40: test40.o
t40a: t40a.o
t40b: t40b.o
t40c: t40c.o
t40d: t40d.o
#t40e: t40e.o
t40f: t40f.o
test41: test41.o
test43: test43.o
test44: test44.o
test45: test45.o
test46: test46.o

test_uname: test_uname.o
hello: hello.o
test_gettimeofday: test_gettimeofday.o
test_getenv: test_getenv.o
test_creat: test_creat.o
statcheck: statcheck.o

all: $(PROGS)

strip:
	$(STRIP) $^

INSTALL_DIR=_install

install: all
	mkdir -p $(INSTALL_DIR)
	cp $(PROGS) $(INSTALL_DIR)
	$(STRIP) $(addprefix $(INSTALL_DIR)/,$(PROGS))
	cp run.sh testsh1.sh testsh2.sh $(INSTALL_DIR)
	chmod +x $(addprefix $(INSTALL_DIR)/,run.sh testsh1.sh testsh2.sh)

clean:
	rm -rf *.o $(PROGS) $(INSTALL_DIR)
