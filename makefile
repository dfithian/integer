tests:
	$(MAKE) library
	g++ -Llib/ -lInteger test/all_tests.cpp -o obj/test.o

library:
	g++ -c src/Integer.cpp
	mv Integer.o obj/
	ar rvs lib/libInteger.a obj/Integer.o

clean:
	rm -rf *.o
	rm -rf *.a
