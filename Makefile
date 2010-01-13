CC = $(CROSS_COMPILE)gcc -O2
STRIP = $(CROSS_COMPILE)strip

PROGS = test1  test2  test3  test4  test5  test6  test7  test8  test9 \
	test11 test12 test13 test14 test15 test16 test17 test18 test19 test20 \
	test21 test22 test23 test24 test25 test26 test27 test28 test29 test30 \
	test31 test32 test33 test34 test35 test36 test37 test38        test40 \
	test41 test43 test44 \
	test_uname \
	hello \
	test_gettimeofday \
	test_getenv \
	test_creat \

test1: test1.c
test2: test2.c
test3: test3.c
test4: test4.c
test5: test5.c
test6: test6.c
test7: test7.c
test8: test8.c
test9: test9.c
test11: test11.c
test12: test12.c
test13: test13.c
test14: test14.c
test15: test15.c
test16: test16.c
test17: test17.c
test18: test18.c
test19: test19.c
test20: test20.c
test21: test21.c
test22: test22.c
test23: test23.c
test24: test24.c
test25: test25.c
test26: test26.c
test27: test27.c
test28: test28.c
test29: test29.c
test30: test30.c
test31: test31.c
test32: test32.c
test33: test33.c
test34: test34.c
test35: test35.c
test36: test36.c
test37: test37.c
test38: test38.c
test40: test40.c
test41: test41.c
test43: test43.c
test44: test44.c

test_uname: test_uname.c
hello: hello.c
test_gettimeofday: test_gettimeofday.c
test_getenv: test_getenv.c
test_creat: test_creat.c

all: $(PROGS)

strip:
	$(STRIP) $^

install: all
	mkdir -p install
	cp $(PROGS) install/
	$(STRIP) $(addprefix install/,$(PROGS))

clean:
	rm -rf *.o $(PROGS) install
